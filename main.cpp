#include <iostream>
#include <SFML/Graphics.hpp>
#include "Objects/Node.h"
#include "Objects/Network.h"
#include "Objects/PersonData.h"
#include "fstream"
#include "Objects/ButtonInterface.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1850, 800), "SFML Works!");
    window.setFramerateLimit(60);

    ButtonInterface interface;

    sf::Texture neighborHoodTexture;
    if (!neighborHoodTexture.loadFromFile("../assets/better_hood.png")) {
        return -1;
    }
    sf::Sprite bgSprite(neighborHoodTexture);

    sf::Texture mericaTexture;
    if (!mericaTexture.loadFromFile("../assets/merica.png")) {
        return -1;
    }


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
                    std::cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << "\n";
                    network.HandleLC(window, sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

                }

                // if (event.mouseButton.button == sf::Mouse::Right) {
                //
                // }
            }
        }

        window.clear(sf::Color(53, 204, 172));
        window.draw(bgSprite);
        network.Display(window);
        interface.DrawInterface(window);
        window.display();
    }
    return 0;
}