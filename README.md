## Cellular-Automata-Simulator

| Command | Explanation |
| ----- | ---- |
| new n | Creates a new <img src="https://render.githubusercontent.com/render/math?math=n \cdot n"> grid, where <img src="https://render.githubusercontent.com/render/math?math=n \ge 1">. |
| init | Enters initialization mode. Subsequently read pairs of integers x y and sets the cell at coordinates (x, y) as alive. The coordinates -1 -1 end initialization mode. It is possible to enter initialization mode more than once, even while the simulation is running. |
| step | Runs one tick of the simulation, i.e. transforms the grid into the immediately succeeding generation.|
| steps n | Runs n steps of the simulation. |
| print | Prints the grid |

> For detailed information, please see [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)
