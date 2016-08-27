//
//  grass.hpp
//  gridgame
//
//  Created by SLIN63 on 8/17/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#ifndef grass_hpp
#define grass_hpp

#include "staticobject.hpp"

class Grass : public StaticObject {
public:
    Grass();
    Grass(const CRDS&);

private:
    char static_symbol = ',';
    int static_draw_priority = 6;
    int static_health = 1;
    Symbol::Effect static_color = Symbol::GREEN; // ANSI-Green
};

#endif /* grass_hpp */
