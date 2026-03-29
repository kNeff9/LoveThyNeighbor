//
// Created by kevin on 3/27/2026.
//

#pragma once

#include <iostream>
#include "Node.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "NeighborhoodInterface.h"
#include "BFS.h"

void NeighborhoodInterface::HandleLC(sf::RenderWindow &window, int x, int y) {


    if (x < 0 || x >= window.getSize().x) {
        return;
    }

    if (y < 0 || y >= window.getSize().y) {
        return;
    }

    sf::Vector2<float> clickCoords = window.mapPixelToCoords({x, y});

    if (switch_button_spr.getGlobalBounds().contains(clickCoords)) {
        RandomizeItem();
        std::string newItem = desiredItem.getString();
        network.desiredItem = newItem;
    }

    if (dfsButtonSpr.getGlobalBounds().contains(clickCoords)) {
        return;
    }

    if (bfsButtonSprite.getGlobalBounds().contains(clickCoords)) {

        // searchResult res = network.bfs.iterative(network.startingNode, desiredItem.getString());
        //
        // if (res.found) {
        //     UpdateFoundNode(res.target);
        // }

        // std::cout << network.startingNode->name << " " << network.desiredItem << "\n";

        // Node* res = network.iterativeBFS(network.startingNode, desiredItem.getString());
        // UpdateFoundNode(res);
    }

    for (Node* n : network.people) {

        if (n->shape.getGlobalBounds().contains(clickCoords)) {

            if (network.startingNode != nullptr) {
                network.startingNode->shape.setFillColor(sf::Color::Blue);
            }

            network.startingNode = n;
            network.startingNode->shape.setFillColor(sf::Color::Red);

            UpdateStartingNode(network.startingNode);
        }
    }


}