#include "Menu.hpp"
#include "gameStart.hpp"
#include "RecordsMenu.hpp"
#include <SFML/Graphics.hpp>
#include <fmt/base.h>
#include <fstream>


//this page is contain Start menu codes
void Menu(){

    auto window = sf::RenderWindow(
           sf::VideoMode({1080, 720}), "Welcome to Number One!"
       );
   // Load Assets
    //Load font
    auto san_serif=sf::Font();
    if (!san_serif.openFromFile("../Assets/Fonts/BungeeSpice.ttf"))
    {
        fmt::println("{}", "Failed to load SanSerif font");
    }
    //Load button texture
    auto menu_btn=sf::Texture();
    if (!menu_btn.loadFromFile("../Assets/ButtonTextures/woodenBtn.png")) {
        fmt::println("{}", "Failed to load woodenBtn.png");
    }
    //Load backward button
    auto backBtn=sf::Texture();
    if (!backBtn.loadFromFile("../Assets/ButtonTextures/backArrow.png")) {
        fmt::println("{}", "Failed to load backArrow.png");
    }
    //Load BackGround texture
    auto menu_background=sf::Texture();
    if (!menu_background.loadFromFile("../Assets/Images/bgpicture.png")) {
        fmt::print("{}", "Failed to load background texture");
    }
    //Load Records File
    std::ifstream records("../Assets/records/records.txt");
    if (!records) {
        fmt::println("{}", "Could not load words list");
        return;
    }
    //Load Instruction page background
    auto instruction_texture=sf::Texture();
    if (!instruction_texture.loadFromFile("../Assets/Images/bg_instruction.png")) {
        fmt::print("{}", "Failed to load instruction texture");
    }
    //sprite of backgrounds
    sf::Sprite instruction(instruction_texture);
    sf::Sprite background(menu_background);

//welcome text settings
    auto welcome_top= sf::Text (san_serif);
    welcome_top.setFont(san_serif);
    welcome_top.setCharacterSize(32);
    welcome_top.setFillColor(sf::Color::White);
    welcome_top.setString("Welcome to NumberOne \n typing game Challange");
    welcome_top.setPosition({300,100});
    //start button settings
    auto start_game= sf::Text (san_serif);
    start_game.setFont(san_serif);
    start_game.setCharacterSize(18);
    start_game.setFillColor(sf::Color::White);
    start_game.setString("StartGame");
    start_game.setPosition({470,310});
    start_game.setFillColor(sf::Color::White);

    auto start_btn_shape = sf::RectangleShape({150, 50});
    start_btn_shape.setTexture(&menu_btn);
    start_btn_shape.setPosition({450,300});

    //record button settings
    auto record_text= sf::Text (san_serif);
    record_text.setFont(san_serif);
    record_text.setCharacterSize(18);
    record_text.setFillColor(sf::Color::White);
    record_text.setString("Records");
    record_text.setPosition({480,395});
    record_text.setFillColor(sf::Color::White);

    auto record_shape = sf::RectangleShape({150, 50});
    record_shape.setTexture(&menu_btn);
    record_shape.setPosition({450,385});

    //instruction button settings
    auto Instruction= sf::Text (san_serif);
    Instruction.setFont(san_serif);
    Instruction.setCharacterSize(18);
    Instruction.setFillColor(sf::Color::White);
    Instruction.setString("Instruction");
    Instruction.setPosition({460,480});
    Instruction.setFillColor(sf::Color::White);

    auto Instruction_shape = sf::RectangleShape({150, 50});
    Instruction_shape.setTexture(&menu_btn);
    Instruction_shape.setPosition({450,470});
    //exit button settings
    auto exit_text= sf::Text (san_serif);
    exit_text.setFont(san_serif);
    exit_text.setCharacterSize(18);
    exit_text.setFillColor(sf::Color::White);
    exit_text.setString("Exit");
    exit_text.setPosition({500,565});
    exit_text.setFillColor(sf::Color::White);

    auto exit_shape = sf::RectangleShape({150, 50});
    exit_shape.setTexture(&menu_btn);
    exit_shape.setPosition({450,555});
    //backward button settings
    auto back_btn_shape = sf::RectangleShape({70, 70});
    back_btn_shape.setTexture(&backBtn);
//booleans for better event handeling
    auto start_button_isPeressed=false;
    auto record_button_isPeressed=false;
    auto Instruction_shape_isPeressed=false;
    auto back_btn_shape_isPeressed=false;


    while (window.isOpen())
    {
        while (auto const event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())window.close();
            //mouse event controlling
            if (auto const e = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                    sf::Vector2f mousePosition = static_cast<sf::Vector2f>(e->position);


                    if (start_btn_shape.getGlobalBounds().contains(mousePosition)) {
                        start_button_isPeressed = true;
                        start_game.setFillColor(sf::Color::Black);
                    }
                    if (record_shape.getGlobalBounds().contains(mousePosition)) {
                        record_button_isPeressed = true;
                        record_text.setFillColor(sf::Color::Black);
                    }
                    if (Instruction_shape.getGlobalBounds().contains(mousePosition)) {
                        Instruction_shape_isPeressed=true;

                    }
                    if (back_btn_shape.getGlobalBounds().contains(mousePosition)) {
                        back_btn_shape_isPeressed=true;

                    }
                    if (exit_shape.getGlobalBounds().contains(mousePosition)) {

                        exit_text.setFillColor(sf::Color::Black);
                        window.close();
                    }
                }
            }
        }

        //draw all objects
        window.draw(background);
        window.draw(start_btn_shape);
        window.draw(start_game);
        window.draw(Instruction_shape);
        window.draw(Instruction);
        window.draw(record_shape);
        window.draw(record_text);
        window.draw(welcome_top);
        window.draw(exit_shape);
        window.draw(exit_text);
        if (record_button_isPeressed) {
            window.close();
            Record();
        }
        if (Instruction_shape_isPeressed) {
            window.clear();
            window.draw(instruction);
            window.draw(back_btn_shape);
            if (back_btn_shape_isPeressed) {
                window.close();
                Menu();
            }
        }
        if (!start_button_isPeressed) {
            window.draw(start_game);
        }
        if (start_button_isPeressed) {
            window.close();
            gameStart();
            return ;
        }


        window.display();
    }
}

