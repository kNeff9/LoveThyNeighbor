#include <iostream>
#include <SFML/Graphics.hpp>
#include "Objects/Node.h"
#include "Objects/Network.h"
#include "Objects/PersonData.h"
#include "fstream"

int main() {
    sf::RenderWindow window(sf::VideoMode(1800, 770), "SFML Works!");
    window.setFramerateLimit(60);

    sf::Texture bgTexture;
    if (!bgTexture.loadFromFile("../assets/neighborhood.png")) {
        return -1;
    }
    sf::Sprite bgSprite(bgTexture);

    Network network;
    PersonData personData;

    std::ofstream coords("../persondata/house_coords.txt", std::ios::app);

    // network.Populate(personData);
    network.TestPopulate(personData);

    network.PrintNames();

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {

                if (event.mouseButton.button == sf::Mouse::Left) {

                    // coords << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << "\n";
                    network.HandleLC(window, sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

                }

                // if (event.mouseButton.button == sf::Mouse::Right) {
                //
                // }
            }
        }

        window.clear();
        window.draw(bgSprite);
        network.Display(window);
        window.display();
    }
    return 0;
}