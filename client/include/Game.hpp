/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** Game
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
// #include <boost/asio.hpp>
#include <iostream>
#include "./Utilities/Clock.hpp"
#include "./Utilities/Picture.hpp"
#include "./Utilities/Text.hpp"
#include "./Utilities/TextButton.hpp"
#include "./Utilities/Moveback.hpp"
#include "Window.hpp"
#include "./Network/network_include.hpp"
#include "./Utilities/FPS.hpp"

/**
 * @brief Game class
 *
 */
class Game
{
public:
    enum Scene
    {
        MENU,
        LOBBY,
        LOBBY_SELECTION,
        GAME,
        NONE,
        PAUSE,
        SETTING
    };

    /**
     * @brief Construct a new Game object
     *
     */
    Game(sf::RenderWindow &window, const std::string &ip, const std::string &name, rt::Socket *socket);

    /**
     * @brief Destroy the Game object
     *
     */
    ~Game();

    /**
     * @brief Init the Game
     *
     */
    void run();

    /**
     * @brief Draw the Game
     *
     */
    void display();

    /**
     * @brief initialize menu
     *
     */
    void menu_init();

    /**
     * @brief initialize lobby
     *
     */
    void lobby_init();

    /**
     * @brief initialize lobby selection
     *
     */
    void lobby_selection_init();

    /**
     * @brief initialize game
     *
     */
    void game_init();

    /**
     * @brief initialize pause
     *
     */
    void pause_init();

    /**
     * @brief update menu
     *
     */
    void draw_scene();

    /**
     * @brief input handler
     *
     */
    void events_handler();

    /**
     * @brief handle menu events
     *
     */
    void menu_events();

    /**
     * @brief handle lobby events
     *
     */
    void lobby_events();

    /**
     * @brief handle lobby selection events
     *
     */
    void lobby_selection_events();

    /**
     * @brief handle game events
     *
     */
    void game_events();

    /**
     * @brief handle pause menu events
     *
     */
    void pause_events();

    /**
     * @brief settings menu
     *
     */
    void settings_menu();

    /**
     * @brief handle settings menu events
     *
     */
    void settings_events();

    /**
     * @brief display fps
     *
     */
    void display_fps();

protected:
private:
    sf::RenderWindow &_window;

    Moveback _moveback;

    sf::Music _music;
    // sf::Music _music_game;
    sf::Sound _shoot;
    sf::SoundBuffer _shoot_buffer;

    Scene _scene;
    sf::Text text;
    sf::Text scoretext;
    std::vector<Picture *> _basePictures;
    std::vector<Button *> _baseButtons;
    std::vector<Picture *> _fromServerPictures;
    std::vector<Button *> _fromServerButtons;
    std::vector<Text *> _fromServerTexts;
    std::vector<TextButton *> _fromServerTextButtons;

    std::string _playerName;
    std::string _ip;

    rt::Socket *_socket;

    long _score = 0;

    // boost::asio::ip::udp::endpoint _endpoint;
};