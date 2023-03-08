/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** main
*/

#include "../include/Window.hpp"

int main()
{
    try {
        Window Window(1920, 1080, "R-Type");
        Window.init();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
