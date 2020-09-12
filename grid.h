#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <vector>
#include <cstddef>
#include "cell.h"

class TextDisplay;
class GraphicDisplay;

// Grid is initially empty. Sets up a TextDisplay observer when init() is called
// and the grid is initialized with cell objects.
class Grid {
    TextDisplay *td = nullptr;         // The text display is an observer on each cell.
    GraphicDisplay    *ob = nullptr;         // Graphical display observer attached to each cell.
                                       // Depending upon implementation, may want to make this a
                                       // pointer to GraphicalDisplay object.
    size_t row, col;
    std::vector<std::vector<Cell>> cells;
    // Add private members, if necessary.
 
  public:
    ~Grid();
  
    void init( size_t n );              // Sets up an n x n grid.  Clears old grid, if necessary.
    void turnOn( size_t r, size_t c );  // Marks cell at row r, col c as alive.
    void tick();                        // Next tick of the simulation.
    
    friend std::ostream & operator<<( std::ostream & out, const Grid & g );
};

// Uses the TextDisplay to output the grid information.
std::ostream & operator<<( std::ostream & out, const Grid & g );

#endif
