//
//  grass.cpp
//  gridgame
//
//  Created by SLIN63 on 8/17/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#include "grass.hpp"

Grass::Grass() {
    symbol->set_symbol(static_symbol);
    symbol->set_color(static_color);
    health = static_health;
    draw_priority = static_draw_priority;
    can_interact = static_interact;
}

Grass::Grass(const CRDS& coords) {
    symbol->set_symbol(static_symbol);
    symbol->set_color(static_color);
    health = static_health;
    draw_priority = static_draw_priority;
    can_interact = static_interact;
    c = coords;
}