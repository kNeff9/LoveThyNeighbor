//
// Created by kevin on 3/27/2026.
//

#ifndef PROJECT2_NEIGHBORHOODINTERFACE_H
#define PROJECT2_NEIGHBORHOODINTERFACE_H

#include <iostream>
#include "Node.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "PersonData.h"
#include <map>
#include <cmath>
#include "helperFuncs.h"
#include "Network.h"

struct NeighborhoodInterface {

    PersonData pd;

    sf::Font font;

    sf::Texture bgTexture;
    sf::Sprite bgSprite;

    sf::Texture sidebarTexture;
    sf::Sprite sidebarSprite;

    sf::Text desiredItem;

    sf::Text startingNodeName;

    sf::Text endingNodeName;
    sf::Text timeElapsed;
    sf::Text nodesVisited;

    sf::Sprite switch_button_spr;
    sf::Texture switch_button_texture;
    sf::Sprite dfsButtonSpr;
    sf::Texture dfsTexture;
    sf::Sprite bfsButtonSprite;
    sf::Texture bfsTexture;

    Node* startingNode;

    // Keeping network inside of interface struct
    Network network;


    NeighborhoodInterface() {

        network.TestPopulate(pd);

        if (!font.loadFromFile("../assets/fonts/Lora-Regular.ttf")) {
            throw std::runtime_error("Could not load font");
        }

        bgTexture.loadFromFile("../assets/better_hood.png");
        bgSprite.setTexture(bgTexture);

        sidebarTexture.loadFromFile("../assets/sidebar.png");
        sidebarSprite.setTexture(sidebarTexture);
        sidebarSprite.setPosition(1597, 0);

        switch_button_texture.loadFromFile("../assets/switch_button.png");
        switch_button_spr.setTexture(switch_button_texture);
        switch_button_spr.setPosition(1610, 250);

        dfsTexture.loadFromFile("../assets/dfs_button.png");
        dfsButtonSpr.setTexture(dfsTexture);
        dfsButtonSpr.setPosition(1615, 325);

        bfsTexture.loadFromFile("../assets/bfs_button.png");
        bfsButtonSprite.setTexture(bfsTexture);
        bfsButtonSprite.setPosition(1725, 325);

        configureText(desiredItem, "test item", font, 19, sf::Color::Black);
        setText(desiredItem, 1700, 275);

        configureText(startingNodeName, "", font, 19, sf::Color::Black);
        setText(startingNodeName, 1675, 125);

        configureText(endingNodeName, "ending node", font, 19, sf::Color::Black);
        setText(endingNodeName, 1675, 500);

        configureText(timeElapsed, "time elapsed", font, 19, sf::Color::Black);
        setText(timeElapsed, 1675, 600);

        configureText(nodesVisited, "nodes visited", font, 19, sf::Color::Black);
        setText(nodesVisited, 1675, 700);

    }

    void HandleLC(sf::RenderWindow& window, int x, int y);

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

    void UpdateFoundNode(Node* n) {
        configureText(endingNodeName, n->name, font, 19, sf::Color::Black);
    }

    void DrawInterface(sf::RenderWindow& window) {

        window.draw(bgSprite);
        window.draw(sidebarSprite);
        window.draw(switch_button_spr);
        window.draw(bfsButtonSprite);
        window.draw(dfsButtonSpr);
        window.draw(desiredItem);

        window.draw(endingNodeName);
        window.draw(timeElapsed);
        window.draw(nodesVisited);

        window.draw(startingNodeName);

        network.Display(window);

    }


};

#endif //PROJECT2_NEIGHBORHOODINTERFACE_H