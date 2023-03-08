/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Clock
*/

#pragma once

#include <chrono>

/**
 * @brief Clock class
 *
 */
class Clock {
public:
    /**
     * @brief Construct a new Clock object
     *
     */
    Clock(){};

    /**
     * @brief Destroy the Clock object
     *
     */
    ~Clock(){};

    /**
     * @brief start the clock
     *
     */
    void start();

    /**
     * @brief stop the clock
     *
     */
    void stop();

    void wait() noexcept;

protected:
private:
    std::chrono::time_point<std::chrono::steady_clock, std::chrono::microseconds> _start;
    std::chrono::time_point<std::chrono::steady_clock, std::chrono::microseconds> _end;
    // std::chrono::time_point<std::chrono::_V2::system_clock, std::chrono::microseconds> _start;
    // std::chrono::time_point<std::chrono::_V2::system_clock, std::chrono::microseconds> _end;
};