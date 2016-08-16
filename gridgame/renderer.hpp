//
//  renderer.hpp
//  gridgame
//
//  Created by SLIN63 on 8/15/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//
// http://en.cppreference.com/w/cpp/io/manip

#ifndef renderer_hpp
#define renderer_hpp

#include "grid.hpp"

class RenderBox {
public:
    RenderBox() = default;
    RenderBox(const Grid&);
    void render_grid();

private:
    Grid grid;
};

#endif /* renderer_hpp */
