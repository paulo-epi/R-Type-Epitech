/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Game
*/

#include "../include/Game.hpp"

Game::Game(sf::RenderWindow &window, const std::string &ip, const std::string &name, rt::Socket *socket)
    : _window(window),
    _ip(ip),
    _playerName(name),
    _socket(socket),
    _scene(MENU)
{
    if (!_music.openFromFile("client/assets/music.ogg"))
        std::cerr << "Error while loading menu music" << std::endl;
    _music.setLoop(true);
    _music.setVolume(25);
    _music.play();
    if (!_shoot_buffer.loadFromFile("client/assets/laser.ogg"))
        std::cerr << "Error while loading shoot sound" << std::endl;
    _shoot.setBuffer(_shoot_buffer);
    _shoot.setVolume(25);
    _moveback.addBackground("client/assets/gameBackground.png");
}

Game::~Game()
{
    _window.close();
}

void Game::run()
{
    Clock clock;
    FPS fps;
    sf::Font font;

    while (_window.isOpen()) {
        clock.start();
        fps.update();
        if (!font.loadFromFile("client/assets/arial.ttf")) std::cerr << "Error while loading font" << std::endl;
        text.setFont(font);
        text.setString(std::to_string(fps.getFPS()));
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::Red);
        text.setPosition(1800, 50);
        events_handler();
        display();
        clock.stop();
        clock.wait();
    }
}

void Game::menu_init()
{
    _window.clear();
    _basePictures.clear();
    _baseButtons.clear();
    _fromServerPictures.clear();
    _fromServerButtons.clear();
    _fromServerTexts.clear();
    _fromServerTextButtons.clear();
    _basePictures.emplace_back(new Picture("client/assets/background_menu.jpeg"));
    _baseButtons.emplace_back(new Button("client/assets/join_button.jpeg", 800, 500, 2));
    _baseButtons.emplace_back(new Button("client/assets/hostbutton.jpeg", 800, 600, 2));
    _baseButtons.emplace_back(new Button("client/assets/setting.png", 50, 50, 0.1));
}

void Game::lobby_init()
{
    _window.clear();
    _basePictures.clear();
    _baseButtons.clear();
    _fromServerPictures.clear();
    _fromServerButtons.clear();
    _fromServerTexts.clear();
    _fromServerTextButtons.clear();
    _basePictures.emplace_back(new Picture("client/assets/background_menu.jpeg"));
    _basePictures.emplace_back(new Picture("client/assets/back_interface.png", 160, 300));
    _baseButtons.emplace_back(new Button("client/assets/return_button.png", 180, 320));
    _baseButtons.emplace_back(new Button("client/assets/ready_button.png", 855, 850, 0.3));
    _basePictures.emplace_back(new Picture("client/assets/player1.png", 500, 450, 3));
    _basePictures.emplace_back(new Picture("client/assets/player2.png", 1420, 450, 3));
    _basePictures.emplace_back(new Picture("client/assets/player3.png", 500, 700, 3));
    _basePictures.emplace_back(new Picture("client/assets/player4.png", 1420, 700, 3));
    _socket->send_message(_playerName + "|GET-LOBBY-INFOS");
    printf(("Sended " + _playerName + " |GET-LOBBY-INFOS\n").c_str());
    std::string response = _socket->read_message();
    if (response.find("GAME-READY") != std::string::npos)
        _scene = GAME;
    std::string LobbyName = response.substr(0, response.find('|'));
    _fromServerTexts.emplace_back(new Text(LobbyName, 500, 320, 50));
    std::vector<std::string> PlayersNames;
    std::string names = response.substr(response.find('|') + 1);
    for (int i = 0; i < 4 && names.size() > 0; i++) {
        switch (i) {
            case 0:
                _fromServerTexts.emplace_back(new Text(names.substr(0, names.find(",")), 600, 450));
                break;
            case 1:
                _fromServerTexts.emplace_back(new Text(names.substr(0, names.find(",")), 1220, 450));
                break;
            case 2:
                _fromServerTexts.emplace_back(new Text(names.substr(0, names.find(",")), 600, 700));
                break;
            case 3:
                _fromServerTexts.emplace_back(new Text(names.substr(0, names.find(",")), 1220, 700));
                break;
            default:
                break;
        }
        names.erase(0, names.find(',') + 1);
    }
}

void Game::lobby_selection_init()
{
    _window.clear();
    _basePictures.clear();
    _baseButtons.clear();
    _fromServerPictures.clear();
    _fromServerButtons.clear();
    _fromServerTexts.clear();
    _fromServerTextButtons.clear();
    _basePictures.emplace_back(new Picture("client/assets/background_menu.jpeg"));
    _basePictures.emplace_back(new Picture("client/assets/back_interface.png", 160, 300));
    _baseButtons.emplace_back(new Button("client/assets/return_button.png", 180, 320));
    _baseButtons.emplace_back(new Button("client/assets/Join-Button.png", 855, 850, 0.3));

    _socket->send_message("GET-LOBBIES-LIST");
    std::string response = _socket->read_message();

    if (response.find("NO-INSTANCE") != std::string::npos) {
        _fromServerTexts.emplace_back(new Text("No instances available",800, 500));
    } else {
        for (int i = 0; response.size() > 0; i += 50) {
        std::string lobbyInfos = response.substr(0, response.find(","));
        std::string lobbyName = lobbyInfos.substr(0, lobbyInfos.find('|'));
        std::string lobbyNbrPlayer = lobbyInfos.substr(lobbyInfos.find('|') + 1);
        _fromServerTextButtons.emplace_back(new TextButton(lobbyName + " " + lobbyNbrPlayer + "/4", 850, 400 + i));
        response.erase(0, response.find(',') + 1);
        }
    }
}

void Game::game_init()
{
    _window.clear();
    _basePictures.clear();
    _baseButtons.clear();
    _fromServerPictures.clear();
    _fromServerButtons.clear();
    _fromServerTexts.clear();
    _fromServerTextButtons.clear();
    _music.stop();
    _socket->send_message(_playerName + "|GET-GAME-DATA");
    std::string response = _socket->read_message();

    if (response.find("PAUSED") != std::string::npos)
        _scene = PAUSE;
    while (response.size() > 0 && _scene == GAME) {
        std::string filename;
        float scale, x, y;
        filename = response.substr(0, response.find(","));
        response.erase(0, response.find(',') + 1);
        scale = stof(response.substr(0, response.find(",")));
        response.erase(0, response.find(',') + 1);
        x = stof(response.substr(0, response.find(",")));
        response.erase(0, response.find(',') + 1);
        y = stof(response.substr(0, response.find("|")));
        response.erase(0, response.find('|') + 1);
        _fromServerPictures.emplace_back(new Picture("client/assets/" + filename, x, y, scale));
    }
}

void Game::pause_init()
{
    _window.clear();
    _fromServerButtons.clear();
    _fromServerTextButtons.clear();
    _socket->send_message(_playerName + "|GET-PAUSE-DATA");
    std::string response = _socket->read_message();

    if (response.find("PAUSED") != std::string::npos) {
        _fromServerTextButtons.emplace_back(new TextButton("GAME END CLICK HERE TO CLOSE THE CLIENT", 800, 550));
    } else if (response.find("UNPAUSE") != std::string::npos) {
        _scene = GAME;
    } else if (response.find("GAME ENDED") != std::string::npos)
        _fromServerButtons.emplace_back(new Button("client/assets/resetGameButton.png", 800, 400));
}

void Game::settings_menu()
{
    _window.clear();
    _basePictures.clear();
    _baseButtons.clear();
    _fromServerPictures.clear();
    _fromServerButtons.clear();
    _fromServerTextButtons.clear();

    _basePictures.emplace_back(new Picture("client/assets/background_menu.jpeg"));
    _baseButtons.emplace_back(new Button("client/assets/144.png", 160, 500, 2));
    _baseButtons.emplace_back(new Button("client/assets/60.png", 160, 700, 2));
    _baseButtons.emplace_back(new Button("client/assets/return_button.png", 180, 320, 2));
}

void Game::settings_events()
{
    sf::Event event;
    sf::Vector2i mousePos = sf::Mouse::getPosition(_window);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (_baseButtons.at(0)->isClicked(sf::Vector2f(mousePos))) {
                _window.close();
                _window.create(sf::VideoMode(1920, 1080), "R-Type", sf::Style::Close | sf::Style::Resize);
                _window.setFramerateLimit(144);
        }
        if (_baseButtons.at(1)->isClicked(sf::Vector2f(mousePos))) {
                _window.close();
                _window.create(sf::VideoMode(1920, 1080), "R-Type", sf::Style::Close | sf::Style::Resize);
                _window.setFramerateLimit(60);
        }
        if (_baseButtons.at(2)->isClicked(sf::Vector2f(mousePos))) {
                _scene = MENU;
        }
    }
}

void Game::draw_scene()
{
    _window.clear();
    _moveback.moveBack(_window);
    for (Picture *pic : _basePictures)
        _window.draw(pic->getSprite());
    for (Button *button : _baseButtons)
        _window.draw(button->getSprite());
    for (Picture *pic : _fromServerPictures)
        _window.draw(pic->getSprite());
    for (Button *button : _fromServerButtons)
        _window.draw(button->getSprite());
    for (Text *text : _fromServerTexts)
        _window.draw(text->getText());
    for (TextButton *text : _fromServerTextButtons)
        _window.draw(text->getText());
}

void Game::display()
{
    _window.clear();
    switch (_scene) {
        case MENU:
            menu_init();
            break;
        case LOBBY:
            lobby_init();
            break;
        case LOBBY_SELECTION:
            lobby_selection_init();
            break;
        case GAME:
            game_init();
            break;
        case PAUSE:
            pause_init();
            break;
        case SETTING:
            settings_menu();
            break;
        case NONE:
            break;
        default:
            break;
    }
    draw_scene();
    _window.draw(text);
    _window.draw(scoretext);
    _window.display();
}

void Game::menu_events()
{
    sf::Event event;
    sf::Vector2i mousePos = sf::Mouse::getPosition(_window);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (_baseButtons.at(0)->isClicked(sf::Vector2f(mousePos))){
            _scene = LOBBY_SELECTION;
        }
        if (_baseButtons.at(1)->isClicked(sf::Vector2f(mousePos))){
            _socket->send_message(_playerName +"|CREATE-LOBBY");
            std::string response = _socket->read_message();

            if (response.find("LOBBY-CREATED") != std::string::npos)
                _scene = LOBBY;
        }
        if (_baseButtons.at(2)->isClicked(sf::Vector2f(mousePos))){
            _scene = SETTING;
        }
    }
}

void Game::lobby_events()
{
    sf::Event event;
    sf::Vector2i mousePos = sf::Mouse::getPosition(_window);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (_baseButtons.at(0)->isClicked(sf::Vector2f(mousePos))){
            _socket->send_message(_playerName + "|QUIT-LOBBY");
            std::string response = _socket->read_message();
            if (response.find("LOBBY-QUIT") != std::string::npos)
                _scene = MENU;
        }
        if (_baseButtons.at(1)->isClicked(sf::Vector2f(mousePos))){
            _socket->send_message(_playerName + "|SET-READY");
            std::string response = _socket->read_message();
        }
    }
}

void Game::lobby_selection_events()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(_window);
    static int selectedParty = -1;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (_baseButtons.at(0)->isClicked(sf::Vector2f(mousePos))){
            _scene = MENU;
        }
        for (int i = 0; i < _fromServerTextButtons.size(); i++) {
            if (_fromServerTextButtons.at(i)->isClicked(sf::Vector2f(mousePos)))
                selectedParty = i;
        }
        if (selectedParty != -1 && _baseButtons.at(1)->isClicked(sf::Vector2f(mousePos))) {
            _socket->send_message(_playerName + "|JOIN-LOBBY," + std::to_string(selectedParty));
            std::string response = _socket->read_message();
            if (response.find("LOBBY-JOINED") != std::string::npos) {
                _scene = LOBBY;
            }
        }

    }
}

void Game::game_events()
{
    sf::Event event;
    std::string input = _playerName + "|MOVE,";

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        _socket->send_message(_playerName+"|SET-END");
            _scene = PAUSE;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        _socket->send_message(input += "UP");
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        _socket->send_message(input += "DOWN");
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        _socket->send_message(input += "LEFT");
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        _socket->send_message(input += "RIGHT");
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        _shoot.play();
        _socket->send_message(_playerName + "|SHOT");
    }
}

void Game::pause_events()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(_window);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (_fromServerTextButtons.size() > 0 && _fromServerTextButtons.at(0)->isClicked(sf::Vector2f(mousePos))){
            _socket->send_message(_playerName + "|UNPAUSE");
            _scene = GAME;
        }
        if (_fromServerButtons.size() > 0 && _fromServerButtons.at(0)->isClicked(sf::Vector2f(mousePos))){
            _socket->send_message(_playerName + "|RELAUNCH");
            _scene = GAME;
        }
    }
}

void Game::events_handler()
{
    sf::Event event;

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            if (_scene == GAME || _scene == LOBBY) {
                _socket->send_message(_playerName + "|QUIT-CLIENT");
                std::string response = _socket->read_message();
                if (response.find("BYE")){
                    _scene = NONE;
                    std::cout << "alive" << std::endl;
                    _music.stop();
                    _window.close();
                }
            } else {
                _window.close();
                _music.stop();
            }
        }
        switch (_scene) {
            case MENU:
                menu_events();
                break;
            case LOBBY:
                lobby_events();
                break;
            case LOBBY_SELECTION:
                lobby_selection_events();
                break;
            case GAME:
                game_events();
                break;
            case PAUSE:
                pause_events();
                break;
            case SETTING:
                settings_events();
                break;
            case NONE:
                break;
            default:
                break;
        }
    }
}
