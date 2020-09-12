// Created Time: Wed 15 Jul 2020 07:32:01 PM EDT
#include "cell.h"
using namespace std;

Cell::Cell(size_t r, size_t c): nb{0}, info{State::Dead, r, c} {}


void Cell::setLiving(){
    info.state = State::Alive;
}

void Cell::reset(){ // Resets neighbour count to 0.
    nb = 0;
}

// Grid calls this to get me to notify my neighbours if I'm alive.
// Also needs to be called when state is set to be alive so displays are notified.
void Cell::notify() {
    notifyObservers();
}

// My neighbours will call this to let me know if they're alive.
void Cell::notify( Subject & whoNotified ) {
    if(whoNotified.getInfo().state == State::Alive) nb += 1;
}
                                            
// Reassess my living-or-dead status, based on info from neighbours.
void Cell::recalculate(){
    if (nb < 2 || nb > 3) info.state = State::Dead;
    else{
        if (nb == 3) info.state = State::Alive;
    }

} 

// Observer calls this to get information about cell.
Info Cell::getInfo() const {
    return info;
}




