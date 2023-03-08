/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include "../include/basics.hpp"
#include "instance/Instance.hpp"


namespace rt
{
    class RtServer;

    /**
     * @brief Client Connection class
     *
     */
    class ClientConnection : public boost::enable_shared_from_this<ClientConnection> // keep the tcp_connection object alive
    {
    public:
        /**
         * @brief Construct a new Client Connection object
         *
         * @param io_service
         * @param context
         * @param id
         */
        ClientConnection(boost::asio::io_service &io_service, rt::RtServer *context, int id);

        /**
         * @brief Destroy the Client Connection object
         *
         */
        ~ClientConnection();

        /**
         * @brief Get the Socket object
         *
         * @param io_service
         * @param context
         * @param id
         * @return boost::shared_ptr<ClientConnection>
         */
        static boost::shared_ptr<ClientConnection> create(boost::asio::io_service &io_service, rt::RtServer *context, int id);

        /**
         * @brief Get the Socket object
         *
         * @return tcp::socket&
         */
        boost::asio::ip::tcp::socket &socket();

        /**
         * @brief Start the connection
         *
         */
        void start();

        /**
         * @brief Write to the client
         *
         * @param message
         */
        void write_to(std::string message);

        /**
         * @brief Write udp to the client
         *
         * @param message
         */
        void write_udp_to(std::string message);

        /**
         * @brief Get the id object
         *
         * @return int
         */
        int get_id(void);

        /**
         * @brief Read packets
         *
         */
        void read_packets();

        /**
         * @brief Read udp packets
         *
         */
        void read_udp_packets();

        /**
         * @brief handle the reception
         *
         * @param error
         * @param bytes
         */
        void handle_receive(const boost::system::error_code &error, std::size_t bytes);

        /**
         * @brief Handle read
         *
         * @param error
         */
        void handle_read(const boost::system::error_code &error);

        /**
         * @brief Handle write
         *
         * @param error
         * @param bytes_transferred
         */
        void handle_write(const boost::system::error_code &error, size_t bytes_transferred);

        /**
         * @brief Handle send
         *
         * @param message
         * @param error
         * @param bytes_transferred
         */
        void handle_send(boost::shared_ptr<std::string> message, const boost::system::error_code &error, std::size_t bytes_transferred);

    private:
        int _id;
        boost::asio::ip::tcp::socket _socket;
        boost::asio::ip::udp::socket _udpsocket;
        boost::asio::ip::udp::endpoint _remote_endpoint;
        boost::asio::streambuf _buffer_message;
        boost::asio::streambuf _buffer_message_udp;
        std::string _stack_message;
        boost::array<char, 1> _recv_buffer;
        rt::RtServer *_parent_context = NULL;
    };
}

namespace rt
{
    /**
     * @brief Server class
     *
     */
    class RtServer
    {
    public:
        /**
         * @brief Construct a new Rt Server object
         *
         * @param io_service
         * @param port
         */
        RtServer(boost::asio::io_service &io_service, short port);

        /**
         * @brief Destroy the client entity
         *
         * @param id
         */
        void remove_client(int id);

        /**
         * @brief Get the Port object
         *
         * @return int
         */
        int getPort(void) {return (_port);};

    private:
        /**
         * @brief Start accepting connections
         *
         */
        void start_accept();

        /**
         * @brief Handle accept
         *
         * @param new_connection
         * @param error
         */
        void handle_accept(boost::shared_ptr<rt::ClientConnection> new_connection, const boost::system::error_code &error);

        boost::asio::ip::tcp::acceptor _acceptor;
        boost::asio::io_context *_context = NULL;
        std::vector<boost::shared_ptr<rt::ClientConnection>> _clients_list;
        int _counter_id = 0;
        int _port = 0;
    };
}

#endif /* !SERVER_HPP_ */