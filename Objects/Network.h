#ifndef PROJECT2_NETWORK_H
#define PROJECT2_NETWORK_H

#include <iostream>
#include "Node.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "PersonData.h"
#include <map>
#include <cmath>
#include <unordered_map>
#include "BFS.h"



struct Network {

    std::vector<Node*> people;
    std::vector<sf::RectangleShape> lines;

    Node* startingNode = nullptr;

    //omar - recursive DFS helper func
    bool DFSHelper(Node* curr, const std::string& targetItem, std::unordered_set<Node*>& visited, std::unordered_map<Node*, Node*>& parentMap, Node*& foundNode);
    //omar - helper to check if node has target item
    bool NodehasItem(const Node* node, const std::string& targetItem) const;


    void AddPerson(Node* person) {
        people.push_back(person);
    }

    void TestPopulate(PersonData& pd) {

        for (auto pair : pd.houseCoords) {
            people.push_back(new Node(pd.getRandomName(), pair.first, pair.second));
        }

        for (Node* currHouse : people) {

            for (Node* otherHouse : people) {

                if (currHouse == otherHouse) {
                    continue;
                }

                double distance = std::sqrt( std::pow(currHouse->xpos - otherHouse->xpos, 2) + std::pow(currHouse->ypos - otherHouse->ypos, 2));

                if (distance < 130) {
                    currHouse->friends.insert(otherHouse);

                    AddLine(currHouse, otherHouse, 3);
                    // otherHouse->friends.insert(currHouse);
                }
            }
        }

    }

    void Display(sf::RenderWindow& window) {

        for (auto& line : lines) {
            // window.draw(line.edges, 2, sf::Lines);
            window.draw(line);
        }

        for (Node* n : people) {
            window.draw(n->shape);
        }

    }

    void AddLine(const Node* n, const Node* f, float thickness);

    void HandleLC(sf::RenderWindow& window, int x, int y);

    void PrintNames() {

        for (Node* n : people) {
            std::cout << n->name << "\n";
        }
    }

    // omar - main DFS func that finds first node w target item
    Node* DepthFirstSearch(Node* startNode, const std::string& targetItem);
    // omar - returns full path from start node to found node
    std::vector<Node*> DepthFirstSearchPath(Node* startNode, const std::string& targetItem);

};

#endif //PROJECT2_NETWORK_H




