//
// Created by kevin on 3/24/2026.
//

#pragma once

#include <iostream>
#include "Node.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "PersonData.h"
#include <map>
#include <cmath>
#include "helperFuncs.h"
#include "ButtonInterface.h"

void ButtonInterface::handleLC(sf::RenderWindow &window, int x, int y) {


    if (x < 0 || x >= window.getSize().x) {
        return;
    }

    if (y < 0 || y >= window.getSize().y) {
        return;
    }

    sf::Vector2<float> clickCoords = window.mapPixelToCoords({x, y});

    if (switch_button_spr.getGlobalBounds().contains(clickCoords)) {
        RandomizeItem();
    }


}



