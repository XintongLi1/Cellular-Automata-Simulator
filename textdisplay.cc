// Created Time: Wed 15 Jul 2020 06:09:01 PM EDT
#include "textdisplay.h"
#include "subject.h"
#include "info.h"
using namespace std;

TextDisplay::TextDisplay(size_t n):theDisplay(n, vector<char> (n, '_')){} 

void TextDisplay::notify(Subject & whoNotified){
    size_t y = whoNotified.getInfo().row; // strictly speaking: x in Cartesian Coordinates
    size_t x = whoNotified.getInfo().col;
    if(whoNotified.getInfo().state == State::Alive){
        theDisplay[y][x] = 'X';
    }
    else{
        theDisplay[y][x] = '_';
    }
}

void TextDisplay::notify(){}

ostream & operator<<(ostream & out, const TextDisplay & td){
    for (auto & r : td.theDisplay){
        for (auto & c : r){
            out << c;
        } 
        out << endl;
    }
    return out;
}

