/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** Window
*/

#pragma once

#include <memory>
#include <string>
#include "Utilities/Picture.hpp"
#include "Utilities/Field.hpp"
#include "Utilities/Button.hpp"
#include "Network/network_include.hpp"
#include "Game.hpp"

/**
 * @brief Window class
 *
 */
class Window {
public:
    /**
     * @brief Construct a new Window object
     *
     * @param width The width of the window
     * @param height The height of the window
     * @param windowTitle The title of the window
     */
    Window(int width, int height, std::string windowTitle);

    /**
     * @brief Run the Window
     *
     */
    void run(void);

    /**
     * @brief Init Window class
     *
     */
    void init(void);

    /**
     * @brief connect to the server
     *
     */
    void connect(const std::string &ip, const std::string &port);

    /**
     * @brief Get Window event
     *
     */
    void getEvent(void);

protected:
private:
    Picture _background;
    Button _playButton;
    Field _ipField;
    Field _portField;
    Field _nameField;

    sf::RenderWindow _window;
    bool _isRunning;
    bool _isIpValid;
    bool _isPortValid;
    bool _isNameValid;
    std::string _ip;
    std::string _playerName;
    std::string _port;
    sf::Font _font;

    rt::Socket *_socket;
};