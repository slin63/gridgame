//
//  behavior.hpp
//  gridgame
//
//  Created by SLIN63 on 9/21/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#ifndef behavior_hpp
#define behavior_hpp


class GameObject;


class BehaviorBox {
public:
    static void rand_walk(const int& d = 1, GameObject* g_ptr = nullptr);
    static void chase(GameObject*, GameObject*, bool);
    
};

#endif /* behavior_hpp */
