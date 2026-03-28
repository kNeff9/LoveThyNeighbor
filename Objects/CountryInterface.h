//
// Created by kevin on 3/27/2026.
//

#ifndef PROJECT2_COUNTRYINTERFACE_H
#define PROJECT2_COUNTRYINTERFACE_H

#include <iostream>
#include "Node.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "PersonData.h"
#include <map>
#include <cmath>
#include <unordered_set>
#include <random>
#include "helperFuncs.h"
#include "Country.h"

struct CountryInterface {

    PersonData pd;
    sf::Font font;

    sf::Sprite bgSpr;
    sf::Texture bgTexture;

    sf::Text startingNodeName;
    sf::Text endingNodeName;
    sf::Text timeElapsed;
    sf::Text numNodesVisited;
    sf::Text desiredItemName;

    sf::Sprite bfsButtonSpr;
    sf::Texture bfsTexture;

    sf::Sprite dfsButtonSpr;
    sf::Texture dfsTexture;

    //I am storing the 100k country network inside the interface
    Country countryNetwork;

    CountryInterface() {

        countryNetwork.Populate(pd);

        if (!font.loadFromFile("../assets/fonts/Lora-Regular.ttf")) {
            throw std::runtime_error("Could not load font");
        }

        bgTexture.loadFromFile("../assets/country.png");
        bgSpr.setTexture(bgTexture);
        bgSpr.setPosition(0, 0);

        dfsTexture.loadFromFile("../assets/dfs_button.png");
        dfsButtonSpr.setTexture(dfsTexture);
        dfsButtonSpr.setPosition(664,304);

        bfsTexture.loadFromFile("../assets/bfs_button.png");
        bfsButtonSpr.setTexture(bfsTexture);
        bfsButtonSpr.setPosition(664,430);

        configureText(startingNodeName, countryNetwork.startingNode->name, font, 25, sf::Color::Black);
        setText(startingNodeName, 300, 339);

        configureText(desiredItemName, pd.getRandomItem(), font, 25, sf::Color::Black);
        setText(desiredItemName, 300, 556);


    }

    void DrawInterface(sf::RenderWindow& window) {

        window.draw(bgSpr);
        window.draw(startingNodeName);
        window.draw(desiredItemName);
        window.draw(dfsButtonSpr);
        window.draw(bfsButtonSpr);

    }

    void HandleLC(sf::RenderWindow& window, int x, int y);


};

#endif //PROJECT2_COUNTRYINTERFACE_H