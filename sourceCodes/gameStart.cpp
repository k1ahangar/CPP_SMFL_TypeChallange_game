#include "WordGenerator.hpp"
#include "gameStart.hpp"
#include "RecordMng.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <fmt/ostream.h>
#include "Menu.hpp"

//this page is for main game when you push start you will call this code
void gameStart() {
    sf::RenderWindow window(sf::VideoMode({1080, 720}), "NumberOne");
    window.setFramerateLimit(60);
//finding center for game over or other possible objects
    float center_x = window.getSize().x / 2;
    float center_y = window.getSize().y / 2;

    //Load all Assets...
    //Load fonts
    sf::Font font_1;
    if (!font_1.openFromFile("../Assets/fonts/BungeeSpice.ttf")) {
        fmt::println("{}", "Could not load default font in gameStart.cpp");
        return;
    }
    sf::Font font_2;
    if (!font_2.openFromFile("../Assets/fonts/modak.ttf")) {
        fmt::println("{}", "Could not load default font in gameStart.cpp");
        return;
    }
    sf::Font font_3;
    if (!font_3.openFromFile("../Assets/fonts/Rubic.ttf")) {
        fmt::println("{}", "Could not load default font in gameStart.cpp");
        return;
    }
    sf::Font font_4;
    if (!font_4.openFromFile("../Assets/fonts/SansSerif.ttf")) {
        fmt::println("{}", "Could not load default font in gameStart.cpp");
        return;
    }
    //Load background texture
    auto game_bc=sf::Texture();
    if(!game_bc.loadFromFile("../Assets/Images/game_bc.png")) {
        fmt::print("{}", "Could not load game_bc.png in gameStart.cpp");
        return;
    }

    //defining player
    RecordMng record_mng("Player1", 0);
    //Load score Files
    std::string scoreFile = "../Assets/records/records.txt";
    if (scoreFile.empty()) {
        fmt::println("{}", "Could not load record file in gameStart.cpp");
    }
     //Load words list
    std::ifstream file("../Assets/wordsList/wordsList_1.txt");
    if (!file) {
        fmt::println("{}", "Could not load words list");
        return;
    }
    //Load back button texture
    auto back_arrow = sf::Texture();
    if (!back_arrow.loadFromFile("../Assets/ButtonTextures/backArrow.png")) {
        fmt::println("{}", "Could not load back_arrow.png");
    }
    //Load button background texture
    sf::Texture back_arrow_texture;
    auto button_key=sf::Texture();
    if (!button_key.loadFromFile("../Assets/ButtonTextures/keyBTN.png")) {
        fmt::println("{}", "Could not load button_key.png");
    }
    //Defining assets behaviors...

    //sprite of background
    sf::Sprite backGround(game_bc);
    // PageUp button
    auto button_PGUP=sf::RectangleShape({50,50});
    button_PGUP.setTexture(&button_key);
    button_PGUP.setPosition({1000, 50});

    auto button_PGUP_txt = sf::Text(font_1);
    button_PGUP_txt.setCharacterSize(12);
    button_PGUP_txt.setFillColor(sf::Color::Black);
    button_PGUP_txt.setString("PGUP");
    button_PGUP_txt.setPosition({1010, 70});

    auto button_PGUP_CM = sf::Text(font_1);
    button_PGUP_CM.setCharacterSize(10);
    button_PGUP_CM.setFillColor(sf::Color::White);
    button_PGUP_CM.setString("SpeedUP");
    button_PGUP_CM.setPosition({1005, 100});
    // Page down Button
    auto button_PGDN=sf::RectangleShape({50,50});
    button_PGDN.setTexture(&button_key);
    button_PGDN.setPosition({1000, 120});

    auto button_PGDN_txt = sf::Text(font_1);
    button_PGDN_txt.setCharacterSize(12);
    button_PGDN_txt.setFillColor(sf::Color::Black);
    button_PGDN_txt.setString("PGDN");
    button_PGDN_txt.setPosition({1010, 140});

    auto button_PGDN_CM = sf::Text(font_1);
    button_PGDN_CM.setCharacterSize(10);
    button_PGDN_CM.setFillColor(sf::Color::White);
    button_PGDN_CM.setString("SpeedDown");
    button_PGDN_CM.setPosition({1005, 170});
  //escape button
    auto button_esc_shape=sf::RectangleShape({50,50});
    button_esc_shape.setTexture(&button_key);
    button_esc_shape.setPosition({1000, 190});

    auto button_esc = sf::Text(font_1);
    button_esc.setCharacterSize(12);
    button_esc.setFillColor(sf::Color::Black);
    button_esc.setString("ESC");
    button_esc.setPosition({1010, 210});

    auto button_esc_CM = sf::Text(font_1);
    button_esc_CM.setCharacterSize(10);
    button_esc_CM.setFillColor(sf::Color::White);
    button_esc_CM.setString("Pause");
    button_esc_CM.setPosition({1005, 240});
// CTRL button
    auto button_CRTL_shape=sf::RectangleShape({50,50});
    button_CRTL_shape.setTexture(&button_key);
    button_CRTL_shape.setPosition({1000, 260});

    auto button_CRTL_txt = sf::Text(font_1);
    button_CRTL_txt.setCharacterSize(12);
    button_CRTL_txt.setFillColor(sf::Color::Black);
    button_CRTL_txt.setString("CRTL");
    button_CRTL_txt.setPosition({1010, 290});

    auto button_CRTL_CM = sf::Text(font_1);
    button_CRTL_CM.setCharacterSize(10);
    button_CRTL_CM.setFillColor(sf::Color::White);
    button_CRTL_CM.setString("Font");
    button_CRTL_CM.setPosition({1005, 310});
    //back button for main menu
    auto back_arrow_shape = sf::RectangleShape({30, 30});
    back_arrow_shape.setTexture(&back_arrow);
    back_arrow_shape.setPosition({20, 10});
//score Text
    auto score = sf::Text(font_1);
    score.setCharacterSize(18);
    score.setFillColor(sf::Color::Black);
    score.setString("Score:");
    score.setPosition({900, 10});
//score counter (number)
    auto score_counter = sf::Text(font_1);
    score_counter.setCharacterSize(18);
    score_counter.setFillColor(sf::Color::Black);
    score_counter.setString("0");
    score_counter.setPosition({1000, 10});

//Game Over
    sf::Text game_over(font_1);
    game_over.setCharacterSize(50);
    game_over.setString("Game Over");
    game_over.setFillColor(sf::Color::Red);
    game_over.setPosition({center_x - 180, center_y - 50});
//Pause
    sf::Text pause(font_1);
    pause.setCharacterSize(50);
    pause.setString("pause");
    pause.setFillColor(sf::Color::Red);
    pause.setPosition({center_x - 180, center_y - 50});
//vector and string to store words in one string
    std::vector<std::string> words;
    std::string word;
    while (file >> word) {
        words.push_back(word);
    }
//place to store words in vector for smfl
    std::vector<sf::Text> texts;
    //speeds holds for X axis and ySpeed holds for Y axis
    //i used float to can freely pass any number to it
    std::vector<float> speeds;
    std::vector<float> ySpeeds;
    //Reading user Inputs
    auto userInput=std::string ();
// controlling time for gap between generating words
    sf::Clock timer;
//default words generatin speed
    auto wordSpeed = 1.0f;

    //used for switch later
    auto fontIndex = 0;
    //default font
    auto currentFont=sf::Font ();
    currentFont=font_1;
    //booleans for controlling events
    auto is_pause=false;
    auto gameOver = false;

    while (window.isOpen()) {
        while (auto const event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            //mouse input
            if (auto const e = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                    sf::Vector2f mousePosition = static_cast<sf::Vector2f>(e->position);
                    //if recognize clik on back arrow shape calling menu function
                    if (back_arrow_shape.getGlobalBounds().contains(mousePosition)) {
                        window.close();
                       Menu();
                    }
                }
            }
            //keyboard input controlling
            if (event->is<sf::Event::KeyPressed>()) {
                auto const e = event->getIf<sf::Event::KeyPressed>();
                //if press escape Pause or unPause will happen true->false, false->ture
                if (e->code == sf::Keyboard::Key::Escape) {
                    is_pause = !is_pause;
                }
                //left or right control will change font
                if (e->code == sf::Keyboard::Key::LControl || e->code == sf::Keyboard::Key::RControl) {
                    //by pressing ctrl this 1 will be added to index and index will be %4 which it allows us to come back to first index again
                    fontIndex = (fontIndex + 1) % 4;
                    //simple swicth
                    switch (fontIndex) {
                        case 0: currentFont = font_1; break;
                        case 1: currentFont = font_2; break;
                        case 2: currentFont = font_3; break;
                        case 3: currentFont = font_4; break;
                    }
                }
                //this loop does not allow user to change setting while page is paused
                if (!is_pause) {
                    if (e->code == sf::Keyboard::Key::PageUp) {
                        wordSpeed = std::min(2.0f, wordSpeed + 0.05f);
                    } else if (e->code == sf::Keyboard::Key::PageDown) {
                        wordSpeed = std::max(0.05f, wordSpeed - 0.05f);
                    }
                }
            }
            //controlling users input
            //https://www.sfml-dev.org/tutorials/3.0/window/events/#the-keypressed-and-keyreleased-events
            if (!is_pause && event->is<sf::Event::TextEntered>()) {
                auto const e = event->getIf<sf::Event::TextEntered>();
                char userText = static_cast<char>(e->unicode);
                //if user input were equal by generated text and was not empty text
                if (userText == '\b' && !userInput.empty()) {
                    userInput.pop_back();
                    //make sure is alphabet and not number A-Z
                } else if (std::isalpha(userText)) {
                    userInput += userText;
                }
//controlling scoring system and fall down text effects
                for (size_t i = 0; i < texts.size(); ++i) {
                    if (texts[i].getString() == userInput) {
                        speeds[i] = 0;
                        ySpeeds[i] = 3.0;
                        userInput.clear();
                        record_mng.addPoints(10);
                        record_mng.saveScoreToFile(scoreFile);
                        score_counter.setString(std::to_string(record_mng.getScore()));
                        wordSpeed += 0.01f;
                    }
                }
            }
        }
//draw all objects which we create before
        window.clear(sf::Color::Black);
        window.draw(backGround);
        window.draw(back_arrow_shape);
        window.draw(score);
        window.draw(score_counter);
        window.draw(button_PGUP);
        window.draw(button_PGUP_txt);
        window.draw(button_PGUP_CM);
        window.draw(button_PGDN);
        window.draw(button_PGDN_txt);
        window.draw(button_PGDN_CM);
        window.draw(button_esc_shape);
        window.draw(button_esc);
        window.draw(button_esc_CM);

        if (gameOver) {
            window.draw(game_over);
            window.draw(back_arrow_shape);
        }

        if (is_pause) {
            window.draw(pause);
            window.display();
            continue;
        }
//measuring time if was more than 2 seconds restart timer
        if (timer.getElapsedTime().asSeconds() >= 2.0) {
            timer.restart();
//defining word generator because it must generate word until game is running
            auto text=sf::Text(currentFont);
            //generating random word
            text.setString(words[std::rand() % words.size()-1]);
            text.setCharacterSize(25);
            text.setFillColor(sf::Color::White);
            //local y is becaue to generate in random y axis
            float y = std::rand() % (window.getSize().y - text.getCharacterSize() * 2);
            text.setPosition({0, y});
            texts.push_back(text);
            speeds.push_back(wordSpeed);
            ySpeeds.push_back(0);
        }
// define how fast each word must move along X axis
        for (size_t i = 0; i < texts.size(); ++i) {
            texts[i].move({speeds[i], ySpeeds[i]});
            //if word touches end of screen game over will be true
            if (speeds[i] > 0 && texts[i].getPosition().x >= window.getSize().x) {
                gameOver = true;
                break;
            }
        }
// print generated texts
        for (const auto& text : texts) {
            window.draw(text);
        }

        window.display();
    }
}