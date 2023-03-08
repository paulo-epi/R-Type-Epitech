/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** Window
*/

#include "../include/Window.hpp"

Window::Window(int width, int height, std::string windowTitle)
    : _window(sf::VideoMode(width, height), windowTitle, sf::Style::Close | sf::Style::Resize),
    _background(Picture("client/assets/background.jpg")),
    _playButton(Button("client/assets/playButton.png", 500, 700)),
    _isRunning(false),
    _isIpValid(false),
    _isPortValid(false),
    _isNameValid(false),
    _ip(""),
    _playerName(""),
    _port(""),
    _ipField("client/assets/ip.png"),
    _portField("client/assets/port.png"),
    _nameField("client/assets/name.png")
{
    if (!_font.loadFromFile("client/assets/arial.ttf"))
        throw std::runtime_error("Can't load font");
    else {
        _ipField.setFont(_font);
        _ipField.setPos(500, 500);
        _ipField.setMaxChar(15);
        _portField.setFont(_font);
        _portField.setPos(500, 600);
        _portField.setMaxChar(5);
        _nameField.setFont(_font);
        _nameField.setPos(500, 400);
        _nameField.setMaxChar(15);
    }
    _window.setFramerateLimit(60);
    _window.setVerticalSyncEnabled(true);
    _background.getSprite().setScale(1, 1);
}

void Window::run(void)
{
    _window.clear();
    _window.draw(_background.getSprite());
    _window.draw(_playButton.getSprite());
    _ipField.draw(_window);
    _portField.draw(_window);
    _nameField.draw(_window);
    _window.display();
}

void Window::getEvent(void)
{
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window.close();
        if (event.type == sf::Event::MouseMoved) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(_window);
            sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
            _playButton.isClicked(mousePosF);
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(_window);
                sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                if (_playButton.isClicked(mousePosF) && !_ipField.getString().isEmpty() && !_portField.getString().isEmpty() && !_nameField.getString().isEmpty()) {
                    _ip = _ipField.getString().toAnsiString();
                    _port = _portField.getString().toAnsiString();
                    _playerName = _nameField.getString().toAnsiString();
                    try {
                        printf("isRun\n");
                        _socket = new rt::Socket(_ip, (short)stoi(_port));
                        _isRunning = true;
                        printf("isRunning\n");
                    }
                    catch (Error const &ec) {
                        std::cout << ec.what() << std::endl;
                    }
                    catch (const std::invalid_argument &ec) {
                        std::cout << ec.what() << std::endl;
                    }
                    catch (const std::out_of_range &ec) {
                        std::cout << ec.what() << std::endl;
                    }
                }
                if (_ipField.isClicked(mousePosF) && !_isIpValid) {
                    _isIpValid = true;
                    _isPortValid = false;
                    _isNameValid = false;
                }
                if (_portField.isClicked(mousePosF) && !_isPortValid) {
                    _isIpValid = false;
                    _isPortValid = true;
                    _isNameValid = false;
                }
                if (_nameField.isClicked(mousePosF) && !_isNameValid) {
                    _isIpValid = false;
                    _isPortValid = false;
                    _isNameValid = true;
                }
            }
        }
        if (event.type == sf::Event::TextEntered) {
            if ((event.text.unicode >= 48 && event.text.unicode <= 57) || event.text.unicode == '.' || event.text.unicode == '\b') {
                if (_isIpValid)
                    _ipField.setString(event.text.unicode);
                else if (_isPortValid)
                    _portField.setString(event.text.unicode);
            }
            if ((event.text.unicode >= 65 && event.text.unicode <= 90) || (event.text.unicode >= 97 && event.text.unicode <= 122) || event.text.unicode == '\b' || event.text.unicode == '.' || event.text.unicode == '-' || event.text.unicode == '_' || event.text.unicode == 32) {
                if (!_isIpValid && !_isPortValid)
                    _nameField.setString(event.text.unicode);
            }
        }
    }
    run();
}

void Window::init(void)
{
    while (_window.isOpen()) {
        if (!_isRunning) {
            getEvent();
        }
        else {
            Game game(_window, _ip, _playerName, _socket);
            game.run();
        }
    }
}
