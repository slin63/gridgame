//
//  human.hpp
//  gridgame
//
//  Created by SLIN63 on 8/15/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "coordinates.hpp"
#include "creature.hpp"

class Human : public Creature {
public:
    Human();
    Human(const CRDS&);

private:
    char race_symbol = '@';
    int race_health = 5;
    int creature_draw_priority = 4;
    Symbol::Effect race_color = Symbol::BLUE; // ANSI-Blue
};

#endif /* player_hpp */

