//
//  static.cpp
//  gridgame
//
//  Created by SLIN63 on 8/17/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#include "staticobject.hpp"

void StaticObject::check_alive(void)
{
    if (health <= 0)
    {
        alive = false;
        symbol->set_symbol('x');
        symbol->set_color(Symbol::Effect::WHITE);
    }
}