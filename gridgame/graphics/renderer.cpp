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

RenderBox::RenderBox(const Manager& mgr_n)
{
    mgr = mgr_n;
}

void RenderBox::render_grid(void)
{
    std::vector<GameObject> objs = mgr.get_objects();
    for (auto&& obj : objs)
    {
        obj.print();
    }
}
