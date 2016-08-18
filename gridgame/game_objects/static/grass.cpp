//
//  grass.cpp
//  gridgame
//
//  Created by SLIN63 on 8/17/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#include "grass.hpp"

Grass::Grass() {
    symbol = static_symbol;
    health = static_health;
    color = static_color;
    draw_priority = static_draw_priority;
}

Grass::Grass(const CRDS& coords) {
    symbol = static_symbol;
    health = static_health;
    color = static_color;
    draw_priority = static_draw_priority;
    c = coords;
}