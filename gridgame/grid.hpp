#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include "gameobject.hpp"
// http://stackoverflow.com/questions/817263/is-it-possible-to-create-a-vector-of-pointers

class Grid
{
typedef std::vector<GameObject*> gVec;
public:
    Grid() = default;
    inline gVec get_grid();
    inline void create(GameObject);
    
private:
    gVec grid;
};

Grid::gVec Grid::get_grid(void) { return grid; }

void Grid::create(GameObject g_obj) {
    grid.push_back(&g_obj);
}

#endif
