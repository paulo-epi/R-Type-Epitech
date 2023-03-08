/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** BasicsInclude
*/

#ifndef BASICS_HPP_
#define BASICS_HPP_

    #define DEBUG_MODE 1 //Switch between 1 or 0.

    #define BUFFER_LENGTH 1024

    #ifdef _WIN32
    #define _WIN32_WINNT 0x0A00
    #endif

    //Standard Library//
    #include <iostream>
    #include <unistd.h>
    #include <fcntl.h>
    #include <string>
    #include <vector>
    #include <sstream>
    #include <fstream>
    #include <iostream>
    #include <memory>
    #include <mutex>
    #include <stdexcept>
    #include <algorithm>

    //Boost.Asio Library//
    #include <boost/array.hpp>
    #include <boost/asio.hpp>
    #include <boost/bind.hpp>
    #include <boost/shared_ptr.hpp>
    #include <boost/enable_shared_from_this.hpp>


    //Private Includes//
    #include "../../Error/Error.hpp"

#endif /* !BASICS_HPP_ */