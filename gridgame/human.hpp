//
//  player.hpp
//  gridgame
//
//  Created by SLIN63 on 8/15/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include "gameobject.hpp"

class Human : public GameObject {
public:
    Human() = default;
    Human(const CRDS&);
private:
    char symbol = '@';
};

#endif /* player_hpp */
