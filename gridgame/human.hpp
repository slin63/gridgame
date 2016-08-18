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
    Human()
    {
        set_symbol(race_symbol), set_health(race_health), set_color(race_color);
    }
    Human(const CRDS&);

private:
    char race_symbol = '@';
    int race_health = 5;
    std::string race_color = "\033[0;34m"; // ANSI-Blue
};

#endif /* player_hpp */
