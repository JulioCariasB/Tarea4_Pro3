#include "Raqueta.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

raqueta::raqueta(){
    player1.setSize(sf::Vector2f(15, 100));
    player1.setFillColor(sf::Color::Blue);
    player1.setPosition(0, 250);
    player2.setSize(sf::Vector2f(15, 100));
    player2.setFillColor(sf::Color::Red);
    player2.setPosition(885,250);
}

sf::RectangleShape raqueta::getPlayer1(){
    return player1;//Retorna el player1 para dibujarlo en el main
}

sf::RectangleShape raqueta::getPlayer2(){
    return player2;//Retorna el player2 para dibujarlo en el main
}

void raqueta::mover(){
    if (frames%3==0) { //Velocidad de la raqueta
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && choqueArriba(player1)) {
            player1.move(0, -1);//Subir
        }else{
            player1.move(0, 1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && choqueAbajo(player1)) {
            player1.move(0, 1);//Bajar
        }else{
            player1.move(0, -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && choqueArriba(player2)) {
            player2.move(0, -1);//Subir
        }else{
            player2.move(0, 1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && choqueAbajo(player2)) {
            player2.move(0, 1);//Bajar
        }else{
            player2.move(0, -1);
        }
    }
    frames++;
}

bool raqueta::choqueArriba(sf::RectangleShape player){
    if (player.getPosition().y==100) {
        return false;
    }
    return true;
}

bool raqueta::choqueAbajo(sf::RectangleShape player){
    if (player.getPosition().y>450) {
        return false;
    }
    return true;
}
