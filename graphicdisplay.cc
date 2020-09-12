// Created Time: Thu 16 Jul 2020 11:10:16 AM EDT
#include "graphicdisplay.h"
#include "subject.h"

using namespace std;

GraphicDisplay::GraphicDisplay(size_t n):
    xw(),
    size{n},
    theDisplay(n, vector<int>(n, 0)){
        for (int i = 0; i < size; ++i){
            for (int j = 0; j < size; ++j){
                xw.fillRectangle(0, 0, 500, 500, Xwindow::White);
            }
        }
    }

void GraphicDisplay::notify(Subject & whoNotified){
    size_t y = whoNotified.getInfo().row; // strictly speaking: x in Cartesian Coordinates
    size_t x = whoNotified.getInfo().col;
    if(whoNotified.getInfo().state == State::Alive){
        theDisplay[y][x] = 1;
    }
    else{
        theDisplay[y][x] = 0;
    }
}
    

int min(int a, int b){
    if (a <= b) return a;
    else return b;
}

void GraphicDisplay::notify(){ // grid.cc will call this as (out << grid) is called.
    size_t s = min(500 / size, 100);
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            if (theDisplay[i][j] == 1){
                xw.fillRectangle(j * s, i * s, s, s, Xwindow::Black);
            }
            else{
                xw.fillRectangle(j * s, i * s, s, s, Xwindow::White);
            }
        }
    }
}

