#include <iostream>
#include <SFML/Graphics.hpp>
#include "Objects/Node.h"
#include "Objects/Network.h"
#include "Objects/PersonData.h"
#include "fstream"
#include "Objects/ButtonInterface.h"
#include "Objects/Country.h"
#include "Objects/CountryInterface.h"
#include "Objects/NeighborhoodInterface.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({1850, 800}), "SFML Works!");
    window.setFramerateLimit(60);

    std::ofstream coords("../persondata/state_coords.txt", std::ios::app);

    CountryInterface countryInterface;
    NeighborhoodInterface neighborhoodInterface;

    bool onNeighborhood = true;

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {


                if (event.mouseButton.button == sf::Mouse::Left) {

                    auto x = sf::Mouse::getPosition(window).x;
                    auto y = sf::Mouse::getPosition(window).y;

                    // std::cout << x << " " << y << "\n";

                    // coords << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << "\n";

                    if (onNeighborhood) {
                        neighborhoodInterface.HandleLC(window, x, y);
                    } else {
                        countryInterface.HandleLC(window, x, y);
                    }
                }
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::S) {
                    onNeighborhood = !onNeighborhood;
                }
            }
        }

        window.clear(sf::Color(53, 204, 172));

        if (onNeighborhood) {
            neighborhoodInterface.DrawInterface(window);
        } else {
            countryInterface.DrawInterface(window);
        }

        window.display();
    }
    return 0;
}
