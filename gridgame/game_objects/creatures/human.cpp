//
//  human.cpp
//  gridgame
//
//  Created by SLIN63 on 8/15/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#include "human.hpp"

Human::Human(const CRDS& coords) {
    c = coords;
    set_symbol(race_symbol);
    set_health(race_health);
    set_color(race_color);
}