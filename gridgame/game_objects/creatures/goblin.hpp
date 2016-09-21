//
//  goblin.hpp
//  gridgame
//
//  Created by SLIN63 on 9/21/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#ifndef goblin_hpp
#define goblin_hpp

#include "creature.hpp"

class Goblin : public Creature {
public:
    Goblin();
    Goblin(const CRDS&);
    
private:
    char race_symbol = 'g';
    int race_health = 10;
    int creature_draw_priority = 4;
    Symbol::Effect race_color = Symbol::GREEN;
    Symbol::Effect race_dead_color = Symbol::RED_BG;
    std::string race_death_msg = "lies gored before you!";
    std::string race_name = "Goblin";
};

#endif /* goblin_hpp */
