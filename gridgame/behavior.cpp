//
//  behavior.cpp
//  gridgame
//
//  Created by SLIN63 on 9/21/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#include "behavior.hpp"
#include "gameobject.hpp"


void BehaviorBox::rand_walk(const int& d, GameObject* g_ptr)
{
    int chance = rand() % 3;
    if (chance == 0)
    {
        int ch = rand() % 4;
        switch(ch)
        {
            case 0 : g_ptr->up(d);
                break;
            case 1 : g_ptr->down(d);
                break;
            case 2 : g_ptr->left(d);
                break;
            case 3 : g_ptr->right(d);
                break;
        }
    }
}

void BehaviorBox::chase(GameObject* chaser, GameObject* chasee)
{
    CRDS chase_v(chasee->get_c_x() - chaser->get_c_x(), chasee->get_c_y() - chaser->get_c_y());
    
    CRDS chase_v_simple = chase_v.largest_component();
    
    // Not sure if this will work
    chaser->down(chase_v_simple.get_y());
    chaser->right(chase_v_simple.get_x());
}
