/*
** EPITECH PROJECT, 2022
** B-OOP-400-NCY-4-1-tekspice-tiago.martins-sousa
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <exception>
#include <iostream>

class Error : public std::exception {
    private:
        std::string _message;

    public:
        Error(std::string const &message);
        virtual ~Error() {};

        virtual const char *what() const noexcept override;
};

#endif /* !ERROR_HPP_ */