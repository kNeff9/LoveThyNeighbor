#pragma once

#include "Network.h"
#include "Node.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>

void Network::AddLine(const Node* n, const Node* f, float thickness) {

    double xdiff = n->xpos - f->xpos;
    double ydiff = n->ypos - f->ypos;
    double distance = sqrt(std::pow(xdiff, 2) + std::pow(ydiff, 2));
    double angle = atan2(-ydiff, -xdiff) * (180 / 3.14159265359);

    sf::RectangleShape line(sf::Vector2f(distance, thickness));
    line.setOrigin(0.0, thickness / 2.0);
    line.setPosition({n->xpos, n->ypos});
    line.setRotation(angle);
    line.setFillColor(sf::Color(255,255,255,40));

    lines.push_back(line);

}


void Network::HandleLC(sf::RenderWindow &window, int x, int y) {


    if (x < 0 || x >= window.getSize().x) {
        return;
    }

    if (y < 0 || y >= window.getSize().y) {
        return;
    }

    sf::Vector2<float> clickCoords = window.mapPixelToCoords({x, y});

    for (Node* n : this->people) {

        if (n->shape.getGlobalBounds().contains(clickCoords)) {

            if (startingNode != nullptr) {
                startingNode->shape.setFillColor(sf::Color::Blue);
            }

            startingNode = n;
            startingNode->shape.setFillColor(sf::Color::Red);
        }
    }


    //         for (Node* f : n->friends) {
    //
    //             double xdiff = n->xpos - f->xpos;
    //             double ydiff = n->ypos - f->ypos;
    //             double distance = sqrt(std::pow(xdiff, 2) + std::pow(ydiff, 2));
    //             double angle = atan2(-ydiff, -xdiff) * (180 / 3.14159265359);
    //
    //             sf::RectangleShape line(sf::Vector2f(distance, 5));
    //             line.setOrigin(0.0, 5 / 2.0);
    //             line.setPosition({n->xpos, n->ypos});
    //             line.setRotation(angle);
    //             line.setFillColor(sf::Color::Red);
    //
    //             lines.push_back(line);
    //
    //             f->shape.setFillColor(sf::Color::Blue);
    //         }
    //     }
    //
    // }

}
