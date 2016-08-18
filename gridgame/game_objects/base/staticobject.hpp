//
//  static.hpp
//  gridgame
//
//  Created by SLIN63 on 8/17/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#ifndef staticobject_hpp
#define staticobject_hpp

#include "gameobject.hpp"

class StaticObject : public GameObject {
protected:
    bool draw = true;
    int draw_priority = 5;
};


#endif /* static_hpp */
