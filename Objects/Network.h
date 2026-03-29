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
#include <unordered_set>



struct Network {

    std::vector<Node*> people;
    std::vector<sf::RectangleShape> lines;
    std::unordered_set<std::string> allItems;

    Node* startingNode = nullptr;
    std::string desiredItem = "";

    BFS bfs;

    //omar - recursive DFS helper func
    bool DFSHelper(Node* curr, const std::string& targetItem, std::unordered_set<Node*>& visited, std::unordered_map<Node*, Node*>& parentMap, Node*& foundNode);
    //omar - helper to check if node has target item
    bool NodehasItem(const Node* node, const std::string& targetItem) const;


    void AddPerson(Node* person) {
        people.push_back(person);
    }

    void TestPopulate(PersonData& pd) {

        for (auto pair : pd.houseCoords) {

            Node* newNode = new Node(pd.getRandomName(), pair.first, pair.second);
            for (int i = 0; i < 3; i++) {
                std::string randItem = pd.getRandomItem();
                newNode->items.insert(pd.getRandomItem());
            }
            people.push_back(newNode);
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

    Node* iterativeBFS(Node* start, const std::string& item);

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




