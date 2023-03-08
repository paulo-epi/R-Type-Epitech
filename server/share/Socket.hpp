/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** Socket
*/

#ifndef Socket_HPP_
#define Socket_HPP_

#include "ISocket.hpp"

namespace rt {
    class Socket : rti::ISocket {
        public:
            Socket(const std::string &hostname, unsigned short port);
            ~Socket();
            void createUdpSocket();

            void send_message(std::string message);
            std::string read_message();

            void send_message_udp(std::string message);
            void handle_send_udp_to(const boost::system::error_code& error, std::size_t bytes);
            void read_message_udp();
            void handle_receive_udp_from(const boost::system::error_code& error, std::size_t bytes);
            void do_write(const std::string &msg);

        protected:
        private:
            boost::asio::ip::udp::endpoint _sender_endpoint;
            boost::asio::streambuf udpbuffer;
            boost::array<char, 1> _recv_buffer;

            //Private Functions//
            std::string get_command();

            //Boost.Asio Variables//
            boost::asio::io_service *_io_service;
            boost::asio::ip::tcp::socket *_socket;
            boost::asio::ip::udp::socket *_udpsocket;

            //Private Variables//
            const std::string &_hostname;
            unsigned short _port;
            int _serverSocket;
            std::string _stack;
            int clientId = 0;
    };
}

#endif /* !Socket_HPP_ */