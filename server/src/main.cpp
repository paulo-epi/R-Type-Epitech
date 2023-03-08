/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** test
*/

#include "../include/basics.hpp"
#include "../share/Socket.hpp"
#include "../include/Server.hpp"


bool only_num(std::string str)
{
  for (char c : str) {
    if (c < '0' || c > '9')
      return (false);
  }
  return (true);
}

void server(std::string port)
{

  if (!only_num(port)) throw Error("[Port] should be composed by only digits.");
  try {
    boost::asio::io_service io_service;
    rt::RtServer server(io_service, stoi(port));

    io_service.run(); //enable async operations
  }
  catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}

/*void client()
{
  try {
    rt::Socket socket("127.0.0.1", 4040);

    std::cout << socket.read_message() << std::endl;
    socket.send_message("wsh alors !");
  }
  catch (Error const &error) {
    std::cout << "Catch an error :\n" << error.what() << std::endl;
  } 
}
*/

int main(int argc, char **argv)
{
  if (argc == 2) {
    try {
      server(std::string(argv[1]));
    }
    catch(Error const &ec) {
      std::cout << "Usage : ./r-type_server [port]" << std::endl;
      std::cout << "Error : " << ec.what() << std::endl;
    }
  }
  else {
    std::cout << "Usage : ./r-type_server [port]" << std::endl;
    return (84);
  }
  return (0);
}