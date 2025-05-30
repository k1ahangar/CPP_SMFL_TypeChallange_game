#include "Menu.hpp"
#include "RecordsMenu.hpp"
#include <SFML/Graphics.hpp>
#include <fmt/core.h>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>



auto loadRecords(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<PlayerRecord> records;

    if (!file) {
        fmt::print("Could not open records file\n");
        return records;
    }

    PlayerRecord record;
    while (file >> record.name >> record.score) {
        records.push_back(record);
    }
    file.close();

    std::sort(records.begin(), records.end(), [](const PlayerRecord& a, const PlayerRecord& b) {
        return a.score > b.score;
    });


    if (records.size() > 10) {
        records.resize(10);
    }

    return records;
}


void Record() {
    auto records = loadRecords("../Assets/records/records.txt");

    sf::RenderWindow window(sf::VideoMode({1080, 720}), "Records");

    sf::Texture background;
    if (!background.loadFromFile("../Assets/Images/records_bg.png")) {
        fmt::print("Could not load background image\n");
    }
    sf::Sprite backgroundSprite(background);

    sf::Font font;
    if (!font.openFromFile("../Assets/fonts/BungeeSpice.ttf")) {
        fmt::print("Could not load font\n");
    }

    sf::Texture back_arrow;
    if (!back_arrow.loadFromFile("../Assets/ButtonTextures/backArrow.png")) {
        fmt::print("Could not load back_arrow.png\n");
    }
    auto record_text=sf::Text(font);
    record_text.setString("Top Record");
    record_text.setFillColor(sf::Color::White);
    record_text.setPosition(sf::Vector2f(50, 50));
    record_text.setCharacterSize(35);


    sf::RectangleShape back_arrow_shape({50, 50});
    back_arrow_shape.setTexture(&back_arrow);
    back_arrow_shape.setPosition({20, 10});

    std::vector<sf::Text> scoreTexts;
    for (size_t i = 0; i < records.size(); ++i) {
        sf::Text text(font);
        text.setFont(font);
        text.setString(fmt::format("{} - Score: {}", records[i].name, records[i].score));
        text.setCharacterSize(20);
        text.setPosition({50, static_cast<float>(100 + (i * 40))});// convertion and put values inside a staticCast https://en.cppreference.com/w/cpp/language/static_cast
        text.setFillColor(sf::Color::White);
        scoreTexts.push_back(text);
    }

    while (window.isOpen()) {
        while (auto const event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())window.close();

            if (auto const e = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                    sf::Vector2f mousePosition = static_cast<sf::Vector2f>(e->position);
                    if (back_arrow_shape.getGlobalBounds().contains(mousePosition)) {
                        back_arrow_shape.setFillColor(sf::Color::Black);
                        window.close();
                        Menu();
                    }
                }
            }

            window.clear();
            window.draw(backgroundSprite);
            window.draw(record_text);
            window.draw(back_arrow_shape);
            for (auto& text : scoreTexts) {
                window.draw(text);
            }
            window.display();
        }
    }
}