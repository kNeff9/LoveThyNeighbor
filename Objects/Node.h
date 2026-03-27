#ifndef PROJECT2_NODE_H
#define PROJECT2_NODE_H

#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <unordered_set>

struct  Node {

    std::string name;
    std::unordered_set<std::string> items;
    // std::vector<Node*> friends;
    std::unordered_set<Node*> friends;

    sf::CircleShape shape;
    float xpos;
    float ypos;
    // sf::Texture texture;
    // sf::Sprite sprite;

    explicit Node(std::string name, float x, float y) {
        this->name = name;

        this->xpos = x;
        this->ypos = y;

        shape.setRadius(8);
        shape.setFillColor(sf::Color::Blue);
        shape.setPosition({x,y});

        shape.setOrigin(sf::Vector2f(5.f, 5.f));
    }

};


#endif //PROJECT2_NODE_H