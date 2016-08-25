//
//  human.cpp
//  gridgame
//
//  Created by SLIN63 on 8/15/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#include "human.hpp"

Human::Human()
{
    symbol = race_symbol;
    health = race_health;
    color = race_color;
    draw_priority = creature_draw_priority;
}

Human::Human(const CRDS& coords)
{
    c = coords;
    symbol = race_symbol;
    health = race_health;
    color = race_color;
    draw_priority = creature_draw_priority;
}