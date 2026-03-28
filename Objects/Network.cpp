#pragma once

#include "Network.h"
#include "Node.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <unordered_map>

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

// omar - checks if current node has the target item
bool Network::NodehasItem(const Node* node, const std::string& targetItem) const {
    for (const std::string& item : node -> items) {
        if (item == targetItem) {
            return true;
        }
    }
    return false;
}

// omar - recursive DFS traversal
bool Network::DFSHelper(Node *curr, const std::string &targetItem, std::unordered_set<Node *> &visited, std::unordered_map<Node *, Node *> &parentMap, Node *&foundNode) {
    if (curr == nullptr) {
        return false;
    }
    visited.insert(curr); // omar - marks node as visited
    if (NodehasItem(curr, targetItem)) { // omar - checks if current node has item
        foundNode = curr;
        return true;
    }
    // omar - explore neighbors recursively
    for (Node* neighbor : curr -> friends) {
        if (visited.find(neighbor) == visited.end()) {
            parentMap[neighbor] = curr; // omar - track path using parent map
            if (DFSHelper(neighbor, targetItem, visited, parentMap, foundNode)) {
                return true;
            }
        }
    }
    return false;
}
// omar - entry point DFS search
Node *Network::DepthFirstSearch(Node *startNode, const std::string &targetItem) {
    if (startNode == nullptr) {
        return nullptr;
    }
    std::unordered_set<Node *> visited;
    std::unordered_map<Node *, Node *> parentMap;
    Node* foundNode = nullptr;
    DFSHelper(startNode, targetItem, visited, parentMap, foundNode);
    return foundNode;
}
// omar - builds path from start to found node
std::vector<Node*> Network::DepthFirstSearchPath(Node *startNode, const std::string &targetItem) {
    std::vector<Node*> path;
    if (startNode == nullptr) {
        return path;
    }
    std::unordered_set<Node *> visited;
    std::unordered_map<Node *, Node *> parentMap;
    Node* foundNode = nullptr;
    bool Found = DFSHelper(startNode, targetItem, visited, parentMap, foundNode);
    if (!Found || foundNode == nullptr) {
        return path;
    }
    Node* curr = foundNode; // omar - reconstruct path w parent map
    while (curr != nullptr) {
        path.push_back(curr);
        if (curr == startNode) {
            break;
        }
        curr = parentMap[curr];
    }
    std::reverse(path.begin(), path.end());
    return path;
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
