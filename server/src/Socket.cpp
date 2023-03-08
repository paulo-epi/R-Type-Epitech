/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** Socket
*/

#include "../share/Socket.hpp"

rt::Socket::Socket(const std::string &hostname, unsigned short port) :
_hostname(hostname), _port(port)
{
    boost::system::error_code ec;
    _io_service = new boost::asio::io_service();
    _socket = new boost::asio::ip::tcp::socket(*_io_service);
    _socket->connect(boost::asio::ip::tcp::endpoint(boost::asio::ip::make_address(_hostname), port), ec);
    std::string response = read_message();
    clientId = stoi(response);
    if (ec) throw Error(ec.message());
    createUdpSocket();

    if (DEBUG_MODE) std::cout << "Connected to server." << std::endl;

    _io_service->run();
}

rt::Socket::~Socket()
{
    _socket->close();
    _udpsocket->close();
    delete _socket;
    delete _udpsocket;
    delete _io_service;
}

void rt::Socket::createUdpSocket()
{
    _udpsocket = new boost::asio::ip::udp::socket(*_io_service);
    _udpsocket->open(boost::asio::ip::udp::v4());
    boost::asio::ip::udp::resolver resolver(*_io_service);
    boost::asio::ip::udp::resolver::query query(boost::asio::ip::udp::v4(), _hostname, std::to_string(_port));
    boost::asio::ip::udp::resolver::iterator itr = resolver.resolve(query);

    _sender_endpoint = *itr;
}

void rt::Socket::send_message(std::string message)
{
    boost::system::error_code ec;
    std::size_t garbage = 0;

    message.push_back('\n');
    send_message_udp(message);
    while (message.size() != 0) {
        garbage = boost::asio::write(*_socket, boost::asio::buffer(message), ec);
        if (ec) throw Error(ec.message());
        message.erase(0, garbage);
    }

    if (DEBUG_MODE) std::cout << "Message sended succesfully." << std::endl;
}

void rt::Socket::send_message_udp(std::string message)
{
    std::cout << "debug udp : " << message << std::endl;
    _udpsocket->async_send_to(
        boost::asio::buffer(message),
        _sender_endpoint,
        boost::bind(
            &Socket::handle_send_udp_to,
            this,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred
        )
    );
    /*std::cout << "debug udp : " << message << std::endl;
    _io_service->post(boost::bind(&Socket::do_write, this, message));*/
}

void rt::Socket::do_write(const std::string &msg)
{
    std::cout << "debug udp : " << msg << std::endl;
    
}

void rt::Socket::handle_send_udp_to(const boost::system::error_code& error, std::size_t bytes)
{
    if (!error) {
    }
    else{
        std::cerr<<"error in handle_send_to:"<<error<<std::endl;
    }
}

std::string rt::Socket::read_message()
{
    boost::system::error_code error_code;

    std::vector<char> buf(1024);
    size_t len = _socket->read_some(boost::asio::buffer(buf), error_code);
    if (!error_code && error_code != boost::asio::error::eof) {
        std::string received_data(buf.begin(), buf.end());
        received_data.resize(len);
        if (DEBUG_MODE) std::cout << "Message readed succesfully :" << received_data << "." << std::endl;
        _stack.append(received_data);
        return get_command();
    } else
        throw Error(error_code.message());
    // boost::system::error_code ec;
    // boost::asio::streambuf buffer;

    // boost::asio::read(*_socket, buffer, boost::asio::transfer_all(), ec);
    // if (ec && ec != boost::asio::error::eof) throw Error(ec.message());
    // else {
    //     if (DEBUG_MODE) std::cout << "Message readed succesfully :" << std::string(boost::asio::buffer_cast<const char *>(buffer.data())) << "." << std::endl;
    //     _stack.append(std::string(boost::asio::buffer_cast<const char *>(buffer.data())));
    //     return (get_command());
    // }
    // return ("");
}

void rt::Socket::read_message_udp()
{
    _udpsocket->async_receive_from(
        boost::asio::buffer(_recv_buffer),
        _sender_endpoint,
        boost::bind(
            &Socket::handle_receive_udp_from,
            this,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred
        )
    );
}

void rt::Socket::handle_receive_udp_from(const boost::system::error_code& error, std::size_t bytes)
{
    throw Error("");
    if(!error) {
    }
    else {
        std::cerr<<"error in handle_receive_from:"<<error<<std::endl;
    }
}

//-----private-----

std::string rt::Socket::get_command(void)
{
    std::stringstream ss(this->_stack);
    std::string buffer;
    std::vector<std::string> commands;

    if (this->_stack.size() == 0)
        return ("");
    while(std::getline(ss, buffer, '\n')){
        if (DEBUG_MODE) std::cout << buffer << std::endl;
        commands.push_back(buffer);
    }
    if (commands.size() == 0 && this->_stack[this->_stack.size() - 1] != '\n')
        return ("");
    this->_stack.erase(0, commands[0].size() + 1);
    if (DEBUG_MODE) std::cout << "debug :" << commands[0] << std::endl;
    return (commands[0]);
}