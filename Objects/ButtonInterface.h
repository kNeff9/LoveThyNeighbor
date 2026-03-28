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

    PersonData pd;

    sf::Font font;

    sf::Text desiredItemTitle;
    sf::Text desiredItem;

    sf::Text startingNodeTitle;
    sf::Text startingNodeName;


    sf::Sprite switch_button_spr;
    sf::Texture switch_button_texture;

    Node* startingNode;


    ButtonInterface() {

        if (!font.loadFromFile("../assets/fonts/Lora-Regular.ttf")) {
            throw std::runtime_error("Could not load font");
        }

        switch_button_texture.loadFromFile("../assets/switch_button.png");
        switch_button_spr.setTexture(switch_button_texture);
        switch_button_spr.setPosition(1610, 126);

        configureText(desiredItemTitle, "Desired Item:", font, 25, sf::Color::Black);
        setText(desiredItemTitle, 1730, 100);

        configureText(desiredItem, "test item", font, 19, sf::Color::Black);
        setText(desiredItem, 1715, 150);

        configureText(startingNodeTitle, "Starting Node:", font, 25, sf::Color::Black);
        setText(startingNodeTitle, 1730, 200);

        configureText(startingNodeName, "", font, 19, sf::Color::Black);
        setText(startingNodeName, 1700, 250);

    }

    void handleLC(sf::RenderWindow& window, int x, int y);

    void RandomizeItem() {

        std::string randomItem = pd.getRandomItem();
        configureText(desiredItem, randomItem, font, 19, sf::Color::Black);

    }

    void UpdateStartingNode(Node* n) {
        startingNode = n;

        if (n != nullptr) {
            configureText(startingNodeName, n->name, font, 19, sf::Color::Black);
        }
    }

    void DrawInterface(sf::RenderWindow& window) {

        window.draw(desiredItemTitle);
        window.draw(switch_button_spr);
        window.draw(desiredItem);

        window.draw(startingNodeTitle);
        window.draw(startingNodeName);

    }


};


#endif //PROJECT2_BUTTONINTERFACE_H