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
    wanders = true;
    dead_color = Symbol::Effect::RED_BG;
    dead_symbol = race_symbol;
    death_msg = "has been torn apart!";
    name = "Human";
}

Human::Human(const CRDS& coords)
{
    c = coords;
    symbol->set_symbol(race_symbol);
    symbol->set_color(race_color);
    health = race_health;
    dead_color = Symbol::Effect::RED_BG;
    dead_symbol = race_symbol;
    draw_priority = creature_draw_priority;
    hides_in_shadows = true;
    wanders = true;
    death_msg = "has been torn apart!";
    name = "Human";
}