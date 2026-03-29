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

    sf::Sprite nodeSwitchSpr;
    sf::Texture nodeSwitchTexture;

    sf::Sprite itemSwitchSpr;
    sf::Texture itemSwitchTexture;

    //I am storing the 100k country network inside the interface
    Country countryNetwork;
    Node* startingNode = nullptr;

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

        nodeSwitchTexture.loadFromFile("../assets/switch_button.png");
        nodeSwitchSpr.setTexture(nodeSwitchTexture);
        nodeSwitchSpr.setPosition(231, 328);

        itemSwitchTexture.loadFromFile("../assets/switch_button.png");
        itemSwitchSpr.setTexture(itemSwitchTexture);
        itemSwitchSpr.setPosition(231, 547);

        configureText(startingNodeName, countryNetwork.startingNode->name, font, 25, sf::Color::Black);
        setText(startingNodeName, 360, 350);

        configureText(desiredItemName, pd.getRandomItem(), font, 25, sf::Color::Black);
        setText(desiredItemName, 360,565);

        configureText(endingNodeName, "", font, 25, sf::Color::Black);
        setText(endingNodeName, 1000, 350);

        configureText(timeElapsed, "0.00", font, 25, sf::Color::Black);
        setText(timeElapsed, 1400, 400);

        configureText(numNodesVisited, "0", font, 25, sf::Color::Black);
        setText(numNodesVisited, 1400, 500);


    }

    void UpdateStartingNode(Node* n) {
        startingNode = n;

        if (n != nullptr) {
            configureText(startingNodeName, n->name, font, 25, sf::Color::Black);
        }
    }

    void UpdateEndingNode(Node* n) {

        if (n != nullptr) {
            configureText(endingNodeName, n->name, font, 25, sf::Color::Black);
            configureText(timeElapsed, countryNetwork.timeTaken, font, 25, sf::Color::Black);
            configureText(numNodesVisited, std::to_string(countryNetwork.vertsTravelled), font, 25, sf::Color::Black);
        } else {
            std::cout << "nonode" << "\n";
        }
    }

    void UpdateDesiredItem(std::string s) {
        configureText(desiredItemName, s, font, 25, sf::Color::Black);
    }

    void DrawInterface(sf::RenderWindow& window) {

        window.draw(bgSpr);
        window.draw(startingNodeName);
        window.draw(desiredItemName);
        window.draw(endingNodeName);
        window.draw(dfsButtonSpr);
        window.draw(bfsButtonSpr);
        window.draw(itemSwitchSpr);
        window.draw(nodeSwitchSpr);
        window.draw(timeElapsed);
        window.draw(numNodesVisited);

    }

    void HandleLC(sf::RenderWindow& window, int x, int y);


};

#endif //PROJECT2_COUNTRYINTERFACE_H