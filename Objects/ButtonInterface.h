#ifndef PROJECT2_BUTTONINTERFACE_H
#define PROJECT2_BUTTONINTERFACE_H

#include <iostream>
#include "Node.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "PersonData.h"
#include <map>
#include <cmath>
#include "helperFuncs.h"

struct ButtonInterface {

    sf::Font font;

    sf::Text desiredItemTitle;
    sf::Text startingNodeTitle;
    sf::Text desiredItem;


    sf::Sprite switch_button_spr;
    sf::Texture switch_button_texture;

    ButtonInterface()
    {

        if (!font.loadFromFile("../assets/fonts/Lora-Regular.ttf")) {
            throw std::runtime_error("Could not load font");
        }
        if (!switch_button_texture.loadFromFile("../assets/switch_button.png")) {
            throw std::runtime_error("Could not load texture");
        }
        switch_button_spr.setTexture(switch_button_texture);
        switch_button_spr.setPosition(sf::Vector2f(1610, 126));

        configureText(desiredItemTitle, "Desired Item:", font, 25, sf::Color::Black);
        setText(desiredItemTitle, 1730, 100);

        configureText(desiredItem, "test item", font, 19, sf::Color::Black);
        setText(desiredItem, 1735, 150);

    }

    void handleLC(sf::RenderWindow& window, int x, int y);

    void RandomizeItem(PersonData& pd) {

        std::string randomItem = pd.getRandomItem();
        configureText(desiredItem, randomItem, font, 19, sf::Color::Black);

    }

    void DrawInterface(sf::RenderWindow& window) {

        window.draw(desiredItemTitle);
        window.draw(switch_button_spr);
        window.draw(desiredItem);

    }


};


#endif //PROJECT2_BUTTONINTERFACE_H