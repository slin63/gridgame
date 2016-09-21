//
//  creature.cpp
//  gridgame
//
//  Created by SLIN63 on 8/17/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#include "creature.hpp"


void Creature::step()
{
    if(player)
    {
        /* Nothing so far! */ ;
    }
    
    else
    {
        check_alive();
        
        if (alive)
        {
            BehaviorBox::rand_walk(1, this);
        }
    }
}


//void Creature::rand_walk(const int& d)
//{
//    int chance = rand() % 3;
//    if (chance == 0)
//    {
//        int ch = rand() % 4;
//        switch(ch)
//        {
//            case 0 : up(d);
//                break;
//            case 1 : down(d);
//                break;
//            case 2 : left(d);
//                break;
//            case 3 : right(d);
//                break;
//        }
//    }
//    
//}
