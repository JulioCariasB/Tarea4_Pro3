#ifndef Pelota_hpp
#define Pelota_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Raqueta.hpp"

class pelota{
public:
    pelota(raqueta* r);
    sf::CircleShape ball;
    sf::RectangleShape ra1;
    sf::RectangleShape ra2;
    sf::Font font;
    sf::Text txt1, txt2;
    int frames = 0;
    bool direccion = false;
    bool se = true;
    bool ne = false;
    bool so = false;
    bool no = false;
    bool stop = false;
    int ia=1;
    int puntos1=0;
    int puntos2=0;
    sf::CircleShape getBall();
    void setRaqueta1(sf::RectangleShape ra1);
    void setRaqueta2(sf::RectangleShape ra2);
    void mover();
    bool choqueArriba();
    bool choqueAbajo();
    bool choqueIzquierda();
    bool choqueDerecha();
    bool choquePaleta1();
    bool choquePaleta2();
    void setCentro();
    void actualizarTxt();
    int ganador();
    void resetear();
    void cargar();
    void guardar(int p1, int p2);
};

#endif /* Pelota_hpp */
