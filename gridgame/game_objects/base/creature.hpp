//
//  creature.hpp
//  gridgame
//
//  Created by SLIN63 on 8/17/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#ifndef creature_hpp
#define creature_hpp
#include "gameobject.hpp"
#include <iostream>

class Creature : public GameObject {
public:
    inline void up(const int&);
    inline void down(const int&);
    inline void left(const int&);
    inline void right(const int&);
    
    void step();
    
protected:
    void rand_walk(const int& d = 1);
};


void Creature::up(const int& d = 1) { c.delta(0, -d); }

void Creature::down(const int& d = 1) { c.delta(0, d); }

void Creature::right(const int& d = 1) { c.delta(d, 0); }

void Creature::left(const int& d = 1) { c.delta(-d, 0); }


#endif /* creature_hpp */
