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
#include <chrono>
#include <queue>

#include "Node.h"
#include "PersonData.h"


struct Node;
struct PersonData;

struct Country {

    std::vector<Node*> allPeople;
    Node* startingNode = nullptr;
    std::string desiredNoun = "";
    int vertsTravelled = 0;
    std::string timeTaken = "0.00";

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

    Node* iterativeBFS(Node* start, const std::string& item) {

        int numTravelled = 0;

        auto startTime = std::chrono::high_resolution_clock::now();

        // std::unordered_set<Node*> visited;
        // std::queue<Node*> q;

        std::unordered_set<Node*> seen;
        std::vector<Node*> holder;
        holder.push_back(start);
        seen.insert(start);

        while (!holder.empty()) {

            std::vector<Node*> tempHolder;

            for (Node* n : holder) {

                for (Node* f : n->friends) {

                    if (seen.count(f)) {
                        continue;
                    }

                    numTravelled++;

                    if (f->items.count(item)) {
                        auto endTime = std::chrono::high_resolution_clock::now();
                        timeTaken = std::to_string(std::chrono::duration<double, std::milli>(endTime - startTime).count());
                        vertsTravelled = numTravelled;
                        return f;
                    }

                    tempHolder.push_back(f);
                    seen.insert(f);
                }
            }

            holder = tempHolder;

        }

        return nullptr;

    }

    Node* iterativeDFS(Node* start, const std::string& item) {
        if (start == nullptr) {
            return nullptr;
        }
        std::unordered_set<Node*> seen;
        std::vector<Node*> nodeStack;
        nodeStack.push_back(start);

        auto startTime = std::chrono::high_resolution_clock::now();
        int numTravelled = 0;


        while (!nodeStack.empty()) {
            Node* currNode = nodeStack.back();
            nodeStack.pop_back();
            if (seen.find(currNode) != seen.end()) {
                continue;
            }
            numTravelled++;
            seen.insert(currNode);

            if (currNode -> items.count(item)) {

                auto endTime = std::chrono::high_resolution_clock::now();
                timeTaken = std::to_string(std::chrono::duration<double, std::milli>(endTime - startTime).count());
                vertsTravelled = numTravelled;
                return currNode;
            }
            for (Node* neighbor : currNode -> friends) {
                if (seen.find(neighbor) == seen.end()) {
                    nodeStack.push_back(neighbor);
                }
            }
        }
        return nullptr;
    }

    std::string GetRandomNoun(PersonData& pd) {

        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> dist(0, allPeople.size() - 1);
        return pd.allNouns.at(dist(rng));

    }



};

#endif //PROJECT2_COUNTRY_HPP