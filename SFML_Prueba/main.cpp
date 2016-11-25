
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Raqueta.hpp"
#include "Pelota.hpp"
#include <stdio.h>

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"

int main(int, char const**)
{
    // Create the main window
    int del = 10*1000;
    sf::RenderWindow window(sf::VideoMode(900, 550), "PONG");
    sf::RectangleShape lineaSuperior, lineaHori, lineaInferior, fondo;
    lineaSuperior.setSize(sf::Vector2f(900, 10));
    lineaSuperior.setFillColor(sf::Color::White);
    lineaSuperior.setPosition(0, 90);
    lineaHori.setSize(sf::Vector2f(10, 450));
    lineaHori.setFillColor(sf::Color::White);
    lineaHori.setPosition(445, 100);
    lineaInferior.setSize(sf::Vector2f(0,90));
    lineaInferior.setFillColor(sf::Color::White);
    lineaInferior.setPosition(0,540);
    sf::Font font;
    if (!font.loadFromFile("ARCADECLASSIC.TTF"))
    {
        // error...
    }
    sf::Text txt;
    txt.setFont(font);
    txt.setCharacterSize(45);
    txt.setColor(sf::Color::Magenta);
    txt.setPosition(250,300);
    fondo.setSize(sf::Vector2f(900, 450));
    fondo.setFillColor(sf::Color::Green);
    fondo.setPosition(0, 100);
    raqueta* raque = new raqueta();
    pelota* pe = new pelota(raque);
    bool activado=true;
    //pe->guardar(20,23);
    //pe->cargar();
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Clear screen
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            activado=true;
            pe->resetear();
            txt.setString("");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
            pe->guardar(pe->puntos1,pe->puntos2);
            return 0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
            pe->cargar();
        }
        if(activado){
            window.clear();
            pe->setRaqueta1(raque->player1);
            pe->setRaqueta2(raque->player2);
            window.draw(fondo);
            window.draw(lineaSuperior);
            window.draw(lineaInferior);
            window.draw(lineaHori);
            window.draw(raque->getPlayer1());
            window.draw(raque->getPlayer2());
            window.draw(pe->getBall());
            window.draw(pe->txt1);
            window.draw(pe->txt2);
            if (pe->ganador()==0) {
                //pe->resetear();
                txt.setString("Ganador Jugador 1");
                activado=false;
            }
            if (pe->ganador()==1) {
                //pe->resetear();
                txt.setString("Ganador Jugador 2");
                activado=false;
            }
            raque->mover();
            pe->mover();
            window.draw(pe->txt1);
            window.draw(pe->txt2);
            window.draw(txt);
            // Update the window
            window.display();
        }
    }

    return EXIT_SUCCESS;
}
