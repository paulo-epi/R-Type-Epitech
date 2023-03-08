/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** Server
*/

#include "../include/Server.hpp"

std::vector<std::shared_ptr<Instance>> instances;


void removeEmptyInstances()
{
    for (int i = 0; i < instances.size(); i++) {
        if (instances.at(i)->GetPlayersCount() == 0)
            instances.erase(instances.begin() + i);
    }
}

rt::ClientConnection::ClientConnection(boost::asio::io_service &io_service, RtServer *context, int id)
    : _socket(io_service),
      _udpsocket(io_service, udp::v4()),
      _remote_endpoint(),
      _parent_context(context),
      _id(id)
{
    boost::asio::socket_base::reuse_address option(true);
    _udpsocket.set_option(option);
    _udpsocket.bind(udp::endpoint(udp::v4(), context->getPort()));
}

rt::ClientConnection::~ClientConnection()
{
    _socket.close();
    _udpsocket.close();
}

static boost::shared_ptr<rt::ClientConnection> create(boost::asio::io_service &io_service, rt::RtServer *context, int id)
{
    return boost::shared_ptr<rt::ClientConnection>(new rt::ClientConnection(io_service, context, id));
}

boost::asio::ip::tcp::socket &rt::ClientConnection::socket()
{
    return _socket;
}

void rt::ClientConnection::start()
{
    write_to(std::to_string(_id));
    read_packets();
    read_udp_packets();
}

void rt::ClientConnection::write_to(std::string message)
{
    boost::asio::async_write(
        _socket,
        boost::asio::buffer(message),
        boost::bind(
            &ClientConnection::handle_write,
            shared_from_this(),
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred
        )
    );
}

void rt::ClientConnection::write_udp_to(std::string message)
{
    boost::shared_ptr<std::string> mmessage(new std::string(message));

    _udpsocket.async_send_to(
        boost::asio::buffer(*mmessage),
        _remote_endpoint,
        boost::bind(
            &ClientConnection::handle_send,
            this,
            mmessage,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred
        )
    );
}

int rt::ClientConnection::get_id(void)
{
    return (_id);
}

void rt::ClientConnection::read_packets()
{
    boost::asio::async_read_until(
        _socket,
        _buffer_message,
        '\n',
        boost::bind(
            &ClientConnection::handle_read,
            shared_from_this(),
            boost::asio::placeholders::error
        )
    );
}

void rt::ClientConnection::read_udp_packets()
{
    _udpsocket.async_receive_from(
        boost::asio::buffer(_recv_buffer),
        _remote_endpoint,
        boost::bind(
            &ClientConnection::handle_receive,
            this,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred
        )
    );
}

void rt::ClientConnection::handle_receive(const boost::system::error_code &error, size_t bytes_transferred)
{
    if (error.failed()) {
        std::cout << error.message() << std::endl;
        return;
    }
    std::string target = _recv_buffer.c_array();

    if (DEBUG_MODE) std::cout << "Buffer : " << target << std::endl;

    read_udp_packets();
}

void rt::ClientConnection::handle_read(const boost::system::error_code &error)
{
    std::ostringstream ss;
    ss << &_buffer_message;
    std::string target = ss.str();

    if (target.size() == 0 && _parent_context) {
        //_parent_context->remove_client(_id);
        delete this;
        return;
    }
    if (DEBUG_MODE) std::cout << "Buffer : " << target << std::endl;
    _stack_message.append(target);

    if (target.find("CREATE-LOBBY") != std::string::npos) {
        std::string playerName = target.substr(0, target.find('|'));
        Player *player = new Player(playerName);
        Instance *instance = new Instance(player);
        instances.emplace_back(instance);
        write_to("LOBBY-CREATED\n");
    }

    if (target.find("GET-LOBBY-INFOS") != std::string::npos) {
        std::string playerName = target.substr(0, target.find('|'));
        for (auto instance : instances) {
            if (instance.get()->playerInLobby(playerName)) {
                if (instance.get()->isGameReady()) {
                    instance.get()->Init();
                    instance.get()->setState(Instance::IN_GAME);
                    write_to("GAME-READY\n");
                }
                else write_to(instance.get()->getInstanceInfos());
            }
        }
    }

    if (target.find("GET-LOBBIES-LIST") != std::string::npos)
    {
        std::string response;
        if (instances.size() > 0) {
            for (auto instance : instances) {
                response.append(instance.get()->getName() + "|" + std::to_string(instance.get()->GetPlayersCount()) + ",");
            }
            write_to(response + "\n");
        } else
            write_to("NO-INSTANCE\n");
    }

    if (target.find("JOIN-LOBBY") != std::string::npos) {
        std::string playerName = target.substr(0, target.find('|'));
        std::string stringInstanceId = target.substr(target.find(",") + 1);
        int instanceId = atoi(stringInstanceId.c_str());
        Player *player = new Player(playerName);
        if (instances.at(instanceId).get()->GetPlayersCount() < 4) {
            instances.at(instanceId).get()->AddPlayer(player);
            write_to("LOBBY-JOINED\n");
        } else {
            write_to("INSTANCE FULL\n");
        }
    }

    if (target.find("QUIT-LOBBY") != std::string::npos) {
        std::string playerName = target.substr(0, target.find('|'));
        for (auto instance : instances) {
            if (instance.get()->playerInLobby(playerName)) {
                instance.get()->RemovePlayer(playerName);
                write_to("LOBBY-QUIT\n");
            }
        }
    }

    if (target.find("GET-GAME-DATA") != std::string::npos) {
        std::string playerName = target.substr(0, target.find('|'));
        for (auto instance : instances) {
            if (instance.get()->getState() == Instance::IN_GAME) {
                if (instance.get()->playerInLobby(playerName)) {
                    write_to(instance.get()->getGameDatas() + "\n");
                }
            }
            if (instance.get()->getState() == Instance::PAUSED) {
                if (instance.get()->playerInLobby(playerName)) {
                    write_to("PAUSED\n");
                }
            }
        }
    }

    if (target.find("MOVE") != std::string::npos) {
        std::string playerName = target.substr(0, target.find('|'));
        for (auto instance : instances) {
            if (instance.get()->getState() == Instance::IN_GAME) {
                if (instance.get()->playerInLobby(playerName)) {
                    ecs::component::Player *player = dynamic_cast<ecs::component::Player *>(instance.get()->getPlayerEntity(playerName).get()->getComponent(ecs::component::PLAYERCOMPONENT).get());
                    player->addCommand(target.substr(target.find(",") + 1));
                }
            }
        }
    }

    if (target.find("SHOT") != std::string::npos) {
        std::string playerName = target.substr(0, target.find('|'));
        for (auto instance : instances) {
            if (instance.get()->getState() == Instance::IN_GAME) {
                if (instance.get()->playerInLobby(playerName)) {
                    ecs::component::Player *player = dynamic_cast<ecs::component::Player *>(instance.get()->getPlayerEntity(playerName).get()->getComponent(ecs::component::PLAYERCOMPONENT).get());
                    // player->addCommand(target.substr(target.find("|") + 1));
                    ecs::component::Position *position = dynamic_cast<ecs::component::Position *>(instance.get()->getPlayerEntity(playerName).get()->getComponent(ecs::component::POSITIONCOMPONENT).get());
                    instance.get()->getEntityPool().AddEntity(ecs::entity::LASER, position);
                }
            }
        }
    }

    if (target.find("SET-READY") != std::string::npos) {
        std::string playerName = target.substr(0, target.find('|'));
        for (auto instance : instances) {
            if (instance.get()->playerInLobby(playerName)) {
                for (auto player : instance.get()->GetPlayers()) {
                    if (player->getPlayerName().find(playerName) != std::string::npos) {
                        player->setIsReady();
                        write_to("STATE-CHANGED\n");
                    }
                }
            }
        }
    }

    if (target.find("QUIT-CLIENT") != std::string::npos) {
        std::string playerName = target.substr(0, target.find('|'));
        for (auto instance : instances) {
            if (instance.get()->playerInLobby(playerName)) {
               instance.get()->RemovePlayer(playerName);
               write_to("BYE");
            }
        }
    }


    if (target.find("GET-PAUSE-DATA") != std::string::npos)
    {
        std::string playerName = target.substr(0, target.find('|'));
        for (auto instance : instances) {
            if (instance.get()->getState() == Instance::PAUSED) {
                if (instance.get()->playerInLobby(playerName)) {
                    if (!instance.get()->getEntityPool().anyPlayerAlive()) {
                        write_to("GAME ENDED\n");
                    } else {
                        write_to("PAUSED\n");
                    }
                }
            }
            if (instance.get()->getState() == Instance::IN_GAME) {
                write_to("UNPAUSE\n");
            }
        }
    }


    if (target.find("SET-END") != std::string::npos)
    {
        std::string playerName = target.substr(0, target.find('|'));
        for (auto instance : instances) {
            if (instance.get()->getState() == Instance::IN_GAME) {
                if (instance.get()->playerInLobby(playerName)) {
                    instance.get()->setState(Instance::PAUSED);
                    write_to("END\n");
                } else {
                    write_to("NO-END\n");
                }
            }
        }
    }

    if (target.find("UNPAUSE") != std::string::npos) {
        std::string playerName = target.substr(0, target.find('|'));
        for (auto instance : instances) {
            if (instance.get()->getState() == Instance::PAUSED) {
                if (instance.get()->playerInLobby(playerName)) {
                    instance.get()->setState(Instance::IN_GAME);
                    // write_to("OK\n");
                }
            }
        }
    }

    if (target.find("RELAUNCH") != std::string::npos) {
        std::string playerName = target.substr(0, target.find('|'));
        for (auto instance : instances) {
            if (instance.get()->getState() == Instance::PAUSED) {
                if (instance.get()->playerInLobby(playerName)) {
                    instance.get()->Init();
                    instance.get()->setState(Instance::IN_GAME);
                    // write_to("OK\n");
                }
            }
        }
    }

    for (auto instance : instances) {
        instance.get()->Update();
    }
    removeEmptyInstances();
    read_packets();
}

void rt::ClientConnection::handle_write(const boost::system::error_code &error, size_t bytes_transferred)
{
    if (DEBUG_MODE)
        std::cout << "Debug Error client_" << _id << " : " << error.message() << std::endl;
}

void rt::ClientConnection::handle_send(boost::shared_ptr<std::string> message, const boost::system::error_code &error, std::size_t bytes_transferred)
{
    if (DEBUG_MODE)
        std::cout << "Debug Error client_" << _id << " : " << error.message() << std::endl;
}

rt::RtServer::RtServer(boost::asio::io_service &io_service, short port)
: _acceptor(io_service, tcp::endpoint(tcp::v4(), port)), _port(port)
{
    _context = &(io_service.get_executor().context());
    start_accept();
}

void rt::RtServer::remove_client(int id)
{
    int i = 0;

    for (boost::shared_ptr<ClientConnection> client : _clients_list) {
        if (client.get()->get_id() == id) {
            //_clients_list.erase(std::remove(_clients_list.begin(), _clients_list.end(), i), _clients_list.end());
        }
        i++;
    }
}

void rt::RtServer::start_accept()
{
    boost::shared_ptr<rt::ClientConnection> new_connection = create(*_context, this, _counter_id);
    _counter_id++;
    _acceptor.async_accept(new_connection->socket(),
                           boost::bind(
                               &RtServer::handle_accept,
                               this,
                               new_connection,
                               boost::asio::placeholders::error));
}

void rt::RtServer::handle_accept(boost::shared_ptr<ClientConnection> new_connection, const boost::system::error_code &error)
{
    if (!error) {
        _clients_list.push_back(new_connection);
        new_connection->start();
    }
    start_accept();
}
