//
// Created by kevin on 3/27/2026.
//

#include "Country.h"
#include "CountryInterface.h"


void CountryInterface::HandleLC(sf::RenderWindow &window, int x, int y) {

    if (x < 0 || x >= window.getSize().x) {
        return;
    }

    if (y < 0 || y >= window.getSize().y) {
        return;
    }

    sf::Vector2<float> clickCoords = window.mapPixelToCoords({x, y});

    if (dfsButtonSpr.getGlobalBounds().contains(clickCoords)) {
        std::string item = desiredItemName.getString();
        Node* res = countryNetwork.iterativeDFS(startingNode, item);
        UpdateEndingNode(res);
    }

    if (bfsButtonSpr.getGlobalBounds().contains(clickCoords)) {
        std::string item = desiredItemName.getString();
        Node* res = countryNetwork.iterativeBFS(startingNode, item);
        UpdateEndingNode(res);
    }

    if (nodeSwitchSpr.getGlobalBounds().contains(clickCoords)) {
        countryNetwork.startingNode = countryNetwork.GetRandomNode();
        UpdateStartingNode(countryNetwork.startingNode);
    }

    if (itemSwitchSpr.getGlobalBounds().contains(clickCoords)) {

        countryNetwork.desiredNoun = countryNetwork.GetRandomNoun(pd);
        UpdateDesiredItem(countryNetwork.desiredNoun);
    }



}
