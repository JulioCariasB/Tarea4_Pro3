
#include "Pelota.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Raqueta.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

pelota::pelota(raqueta* r){
    ball.setRadius(10);
    ball.setPosition(442, 282);
    ball.setFillColor(sf::Color::Yellow);
    ra1 = r->player1;
    ra2 = r->player2;
    if (!font.loadFromFile("ARCADECLASSIC.TTF"))
    {
        // error...
    }
    txt1.setFont(font);
    txt1.setCharacterSize(90);
    txt1.setColor(sf::Color::White);
    txt1.setPosition(370,-10);
    txt2.setFont(font);
    txt2.setCharacterSize(90);
    txt2.setColor(sf::Color::White);
    txt2.setPosition(500,-10);
}

sf::CircleShape pelota::getBall(){
    return ball;
}

void pelota::setRaqueta1(sf::RectangleShape r1){
    ra1 = r1;
}

void pelota::setRaqueta2(sf::RectangleShape r2){
    ra2 = r2;
}

void pelota::mover(){
    actualizarTxt();
    if (frames%2==0) {
        if (!direccion) {
            if (choqueArriba()) {
                se = true;
                ne = false;
                so = false;
                no = false;
            }else if (choqueAbajo()){
                se = false;
                ne = true;
                so = false;
                no = false;
            }else if (choquePaleta2() && ne){
                se = false;
                ne = false;
                so = false;
                no = true;
                direccion=true;
            }else if (choquePaleta2() && se){
                se = false;
                ne = false;
                so = true;
                no = false;
                direccion=true;
            }
        }else{
            if (choqueArriba()) {
                se = false;
                ne = false;
                so = true;
                no = false;
            }else if (choqueAbajo()){
                se = false;
                ne = false;
                so = false;
                no = true;
            }else if (choquePaleta1() && no){
                se = false;
                ne = true;
                so = false;
                no = false;
                direccion=false;
            }else if (choquePaleta1() && so){
                se = true;
                ne = false;
                so = false;
                no = false;
                direccion=false;
            }
        }
        if (se) {
            ball.move(0.5, 1);
        }
        if (ne) {
            ball.move(0.5, -1);
        }
        if (so) {
            ball.move(-0.5,1);
        }
        if (no) {
            ball.move(-1, -1);
        }
        if (choqueDerecha()) {
            puntos1++;
            setCentro();
            direccion = true;
            se = false;
            ne = false;
            so = true;
            no = false;
        }
        if (choqueIzquierda()) {
            puntos2++;
            setCentro();
            direccion = false;
            se = false;
            ne = true;
            so = false;
            no = false;
        }
    }
    frames++;
}

void pelota::setCentro(){
    ball.setPosition(442, 282);
}

bool pelota::choqueArriba(){
    if (ball.getPosition().y==100) {
        ia=2;
        return true;
    }
    return false;
}

bool pelota::choqueAbajo(){
    if (ball.getPosition().y>530) {
        ia=1;
        return true;
    }
    return false;
}

bool pelota::choqueDerecha(){
    if (ball.getPosition().x>900) {
        return true;
    }
    return false;
}

bool pelota::choqueIzquierda(){
    if (ball.getPosition().x<0) {
        return true;
    }
    return false;
}

bool pelota::choquePaleta1(){
    if (ball.getPosition().x==15) {
        if (ra1.getPosition().y<ball.getPosition().y && (ra1.getPosition().y+100)>ball.getPosition().y) {
            //printf("Choque Paleta 1");
            ia=3;
            return true;
        }
    }
    return false;
}

bool pelota::choquePaleta2(){
    if (ball.getPosition().x==865) {
        if (ra2.getPosition().y<ball.getPosition().y && (ra2.getPosition().y+100)>ball.getPosition().y) {
            //printf("Choque Paleta 2");
            ia=3;
            return true;
        }
    }
    return false;
}

void pelota::actualizarTxt(){
    string pts;
    ostringstream convert;
    convert<<puntos1;
    pts = convert.str();
    txt1.setString(pts);
    ostringstream convert1;
    convert1<<puntos2;
    pts = convert1.str();
    txt2.setString(pts);
}

int pelota::ganador(){
    if(puntos1==3){
        printf("Jugador 1");
        return 0;
    }
    if(puntos2==3){
        printf("Jugador 2");
        return 1;
    }
    return -1;
}

void pelota::resetear(){
    bool direccion = false;
    bool se = true;
    bool ne = false;
    bool so = false;
    bool no = false;
    puntos1=0;
    puntos2=0;
    setCentro();
}

void pelota::cargar(){
int p1=0,p2=0;
    ifstream file;
    file.open("Test.txt");
    file>>p1>>p2;
    file.close();
    puntos1=p1;
    puntos2=p2;
}

void pelota::guardar(int p1,int p2){
FILE* pru = fopen("Test.txt","w");
fprintf(pru,"%d %d",p1,p2);
fclose(pru);
}

/*
1 1 SURESTE
-1 1 SUROESTE
1 -1 NORESTE
-1 -1 NOROESTE
*/
