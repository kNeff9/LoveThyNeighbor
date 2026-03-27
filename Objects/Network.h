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



class Network {

    std::vector<Node*> people;
    std::vector<sf::RectangleShape> lines;

public:

    void AddPerson(Node* person) {
        people.push_back(person);
    }


    void TestPopulate(PersonData& pd) {

        for (auto pair : pd.houseCoords) {
            Node* node = new Node(pd.getRandomName(), pair.first, pair.second);
            // people.push_back(new Node(pd.getRandomName(), pair.first, pair.second));

            // Random inventory
            int numItems = 4;
            for (int i = 0; i < numItems; i++) {
                node->items.push_back(pd.getRandomItem());
            }

            people.push_back(node);
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

};

#endif //PROJECT2_NETWORK_H





// void Populate(PersonData& pd) {
    //
    //     std::vector<Node*> currPeople;
    //     currPeople.push_back(new Node(pd.getRandomName(), 100, 100));
    //
    //     std::map<std::pair<float, float>, Node*> seen;
    //     seen[{100, 100}] = currPeople.at(0);
    //     people.push_back(currPeople.at(0));
    //
    //     while (!currPeople.empty() && this->people.size() < 200) {
    //
    //         std::vector<Node*> newPeople;
    //
    //         for (Node* n : currPeople) {
    //
    //             if (n->xpos < 1400) {
    //
    //                 if (seen.count({n->xpos + 100, n->ypos})) {
    //
    //                     n->friends.push_back(seen[{n->xpos + 100, n->ypos}]);
    //                     seen[{n->xpos + 100, n->ypos}]->friends.push_back(n);
    //                 } else {
    //                     Node* rightFriend = new Node(pd.getRandomName(), n->xpos + 100, n->ypos);
    //                     n->friends.push_back(rightFriend);
    //                     newPeople.push_back(rightFriend);
    //                     rightFriend->friends.push_back(n);
    //                     people.push_back(rightFriend);
    //                     seen[{rightFriend->xpos, rightFriend->ypos}] = rightFriend;
    //                 }
    //
    //             }
    //
    //             if (n->ypos < 700) {
    //
    //                 if (seen.count({n->xpos, n->ypos + 100})) {
    //                     n->friends.push_back(seen[{n->xpos, n->ypos + 100}]);
    //                     seen[{n->xpos, n->ypos + 100}]->friends.push_back(n);
    //                 } else {
    //                     Node* leftFriend = new Node(pd.getRandomName(), n->xpos, n->ypos + 100);
    //                     n->friends.push_back(leftFriend);
    //                     newPeople.push_back(leftFriend);
    //                     leftFriend->friends.push_back(n);
    //                     people.push_back(leftFriend);
    //                     seen[{leftFriend->xpos, leftFriend->ypos}] = leftFriend;
    //                 }
    //
    //             }
    //         }
    //
    //         currPeople = newPeople;
    //     }
    // }
