//
// Created by kevin on 3/27/2026.
//

#ifndef PROJECT2_COUNTRY_HPP
#define PROJECT2_COUNTRY_HPP

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

#include "Node.h"
#include "PersonData.h"


struct Node;
struct PersonData;

struct Country {

    std::vector<Node*> allPeople;
    Node* startingNode = nullptr;
    std::string desiredNoun = "";

    void Populate(PersonData& pd) {

        std::vector<std::vector<Node*>> tempHolder;
        int index = 0;

        for (int i = 0; i < 316; i++) {

            std::vector<Node*> newRow;

            for (int j = 0; j < 316; j++) {

                Node* newNode = new Node(pd.allNames.at(index), 0, 0);
                newNode->items.insert(pd.allNouns.at(index));

                // Here I am creating the connections for the nodes
                if (j > 0) {
                    newNode->friends.insert(newRow[j-1]);
                    newRow[j-1]->friends.insert(newNode);
                }

                if (i > 0) {
                    newNode->friends.insert(tempHolder[i-1][j]);
                    tempHolder[i-1][j]->friends.insert(newNode);
                }

                newRow.push_back(newNode);
                index++;
            }

            tempHolder.push_back(newRow);
        }

        for (std::vector<Node*> row : tempHolder) {
            for (Node* n : row) {
                allPeople.push_back(n);
            }
        }

        startingNode = GetRandomNode();

    }

    Node* GetRandomNode() {
        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> dist(0, allPeople.size() - 1);

        return allPeople.at(dist(rng));
    }

    std::string GetRandomNoun(PersonData& pd) {

        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> dist(0, allPeople.size() - 1);
        return pd.allNouns.at(dist(rng));

    }

};

#endif //PROJECT2_COUNTRY_HPP