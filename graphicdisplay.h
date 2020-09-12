#ifndef __GRAPHICDISPLAY_H__
#define __GRAPHICDISPLAY_H__
#include "observer.h"
#include "window.h"
#include <vector>

class Cell;
class Xwindow;

class GraphicDisplay : public Observer{
    Xwindow xw;
    size_t size; // size of the grid;
    std::vector<std::vector<int>> theDisplay; // 1 represents Alive, 0 represents Dead
  public:
    explicit GraphicDisplay (size_t n);
    virtual void notify(Subject & whoNotified) override;
    virtual void notify() override;  

};

#endif
