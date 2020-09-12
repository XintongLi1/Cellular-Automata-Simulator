// Created Time: Wed 15 Jul 2020 05:47:59 PM EDT
#include "grid.h"
#include "textdisplay.h"
#include "graphicdisplay.h"
#include "cell.h"

/* Naming rule for this program:
 * (x, y) -> Cartesian Coordinates
 * (r, c) or (row, col) corresponds to (y, x)
 */

using namespace std;

Grid::~Grid(){
    delete td;
    if (ob) delete ob;
}
void Grid::init(size_t n){
    if (td) { delete td; }
    if (ob) { delete ob; }
    td = new TextDisplay(n);
    ob = new GraphicDisplay(n); 
    vector<vector<Cell>> vec;
    for (size_t i = 0; i < n; ++i){
        vector<Cell> cvec;
        for (size_t j = 0; j < n; ++j){
            cvec.emplace_back(Cell{i, j});
            cvec[j].attach(td);
            cvec[j].attach(ob);

        }
        vec.emplace_back(cvec);
    }
    cells = vec;
    if (n == 1) return;

    // track neighbors
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            for (int k = -1; k <= 1; ++k){
                if (k + i >= 0 && k + i < n){
                    for (int l = -1; l <= 1; ++l){
                        if (l + j >= 0 && l + j < n){
                            if (! (k == 0 && l == 0))
                                cells[i][j].attach(&cells[k+i][l+j]);
                        }
                    }
                }
            }

        }
    }
}

void Grid::turnOn(size_t c, size_t r){
   cells[r][c].setLiving(); 
   td->notify(cells[r][c]);
   ob->notify(cells[r][c]);
}

void Grid::tick(){
    for (auto & y: cells){
        for (auto & x: y){
            x.reset();
        }
    }

    for (auto & y: cells){
        for (auto & x: y){
            x.notify();
        }
    }


    for (auto & y : cells){
        for (auto & x: y){
            x.recalculate();
            td->notify(x);
            ob->notify(x);
        }
    }
}

ostream & operator << (ostream & out, const Grid & g){
    //try{
        g.ob->notify();
    //}
    //catch(exception) {}
    out << *(g.td);
    return out;
}


