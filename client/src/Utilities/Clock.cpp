/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Clock
*/

#include "../include/Utilities/Clock.hpp"

void Clock::wait() noexcept
{
    std::chrono::microseconds elapsed = std::chrono::duration_cast<std::chrono::microseconds>(_end - _start);
    while (elapsed.count() < 16666) {
        stop();
        elapsed = std::chrono::duration_cast<std::chrono::microseconds>(_end - _start);
    }
}

void Clock::start()
{
    _start = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now());
}

void Clock::stop()
{
    _end = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now());
}
