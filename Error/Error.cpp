/*
** EPITECH PROJECT, 2022
** B-OOP-400-NCY-4-1-tekspice-tiago.martins-sousa
** File description:
** Error
*/

#include "Error.hpp"

const char *Error::what() const noexcept
{
    return (_message.c_str());
}

Error::Error(std::string const &message) :
_message(message)
{
}