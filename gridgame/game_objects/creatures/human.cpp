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
    symbol->set_symbol(race_symbol);
    symbol->set_color(race_color);
    health = race_health;
    draw_priority = creature_draw_priority;
    hides_in_shadows = true;
}

Human::Human(const CRDS& coords)
{
    c = coords;
    symbol->set_symbol(race_symbol);
    symbol->set_color(race_color);
    health = race_health;
    draw_priority = creature_draw_priority;
    hides_in_shadows = true;
}