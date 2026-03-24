#ifndef PROJECT2_HELPERFUNCS_H
#define PROJECT2_HELPERFUNCS_H

#include <iostream>
#include "Node.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "PersonData.h"
#include <map>
#include <cmath>

inline void configureText(sf::Text& text, const std::string textBody, sf::Font& font, int size, sf::Color color) {

    text.setFont(font);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setString(textBody);

}

inline void setText(sf::Text &text, float x, float y){

    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
    textRect.top + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(x, y));
}



#endif //PROJECT2_HELPERFUNCS_H