#ifndef PROJECT2_PERSONDATA_H
#define PROJECT2_PERSONDATA_H

#include <iostream>
#include <vector>
// #include <SFML/Graphics.hpp>
#include <fstream>
#include <random>

struct PersonData {

    std::vector<std::string> allNames;
    std::vector<std::string> allItems;
    std::vector<std::pair<int, int>> houseCoords;

    PersonData() {

        std::ifstream nameFile("../persondata/names.txt");
        std::ifstream itemFile("../persondata/items.txt");
        std::ifstream coordsFile("../persondata/house_coords.txt");

        std::string line;
        while (std::getline(nameFile, line)) {
            allNames.push_back(line);
        }

        while (std::getline(itemFile, line)) {
            allItems.push_back(line);
        }

        int currx, curry;

        while (coordsFile >> currx >> curry) {
            houseCoords.emplace_back(currx, curry);
        }

    }

    std::string getRandomName() {

        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> dist(0, allNames.size() - 1);

        return allNames.at(dist(rng));
    }

    std::string getRandomItem() {

        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> dist(0, allItems.size() - 1);

        return allItems.at(dist(rng));

    }
};

#endif //PROJECT2_PERSONDATA_H