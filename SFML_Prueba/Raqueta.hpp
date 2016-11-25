#ifndef Raqueta_hpp
#define Raqueta_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <stdio.h>
class raqueta{
public:
    raqueta();
    sf::RectangleShape player1;
    sf::RectangleShape player2;
    int frames = 0;
    bool direccion = false;
    sf::RectangleShape getPlayer1();
    sf::RectangleShape getPlayer2();
    void mover();
    bool choqueArriba(sf::RectangleShape player);
    bool choqueAbajo(sf::RectangleShape player);
};

#endif /* Raqueta_hpp */
