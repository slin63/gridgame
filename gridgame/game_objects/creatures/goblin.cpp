//
//  goblin.cpp
//  gridgame
//
//  Created by SLIN63 on 9/21/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#include "goblin.hpp"

Goblin::Goblin()
{
    symbol->set_symbol(race_symbol);
    symbol->set_color(race_color);
    health = race_health;
    draw_priority = creature_draw_priority;
    hides_in_shadows = true;
    dead_color = race_dead_color;
    dead_symbol = race_symbol;
    death_msg = race_death_msg;
    name = race_name;
}

Goblin::Goblin(const CRDS& coords)
{
    c = coords;
    symbol->set_symbol(race_symbol);
    symbol->set_color(race_color);
    health = race_health;
    draw_priority = creature_draw_priority;
    hides_in_shadows = true;
    dead_color = race_dead_color;
    dead_symbol = race_symbol;
    death_msg = race_death_msg;
    name = race_name;
}