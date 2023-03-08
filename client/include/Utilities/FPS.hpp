/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** FPS
*/

#ifndef FPS_HPP_
#define FPS_HPP_

#include <SFML/Graphics.hpp>

class FPS
{
public:
    /// @brief Constructor with initialization.
    ///
    FPS() : mFrame(0), mFps(0) {}

    /// @brief Update the frame count.
    ///

    /// @brief Get the current FPS count.
    /// @return FPS count.
    const unsigned int getFPS() const { return mFps; }

private:
    unsigned int mFrame;
    unsigned int mFps;
    sf::Clock mClock;

public:
    void update()
    {
        if (mClock.getElapsedTime().asSeconds() >= 1.f)
        {
            mFps = mFrame;
            mFrame = 0;
            mClock.restart();
        }

        ++mFrame;
    }
};

#endif /* !FPS_HPP_ */
