//
//  renderer.cpp
//  gridgame
//
//  Created by SLIN63 on 8/15/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#include "renderer.hpp"
#include <vector>
#include <iostream>

RenderBox::RenderBox(const Grid& grid_n) {
    grid = grid_n;
}

void RenderBox::render_grid(void) {
    std::vector<GameObject*> objs = grid.get_grid();
    for (auto &&g_obj : objs)
    {
        g_obj->print();
    }
}