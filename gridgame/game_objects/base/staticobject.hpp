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
public:
    void check_alive();
};


#endif /* static_hpp */
