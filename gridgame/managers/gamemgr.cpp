//
//  gamemgr.cpp
//  gridgame
//
//  Created by SLIN63 on 8/30/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#include "gamemgr.hpp"
#include "constants.hpp"
#include <iostream>
#include <unistd.h>


GameMgr::GameMgr()
{
    mgr_ptr = new Manager(GLOBAL_X, GLOBAL_Y);
    rndr_box = new RenderBox(mgr_ptr);
    react_box = new InteractMgr(mgr_ptr->get_player(), mgr_ptr);
    plyr = mgr_ptr->get_player()->get_avatar();
}


void GameMgr::action_menu()
{
    char move;
    
    while(std::cin >> move)
    {
        if (check_input(move))
        {
            if      (move == 'w')
                plyr->up();
            else if (move == 's')
                plyr->down();
            else if (move == 'a')
                plyr->left();
            else if (move == 'd')
                plyr->right();
            step();
        }
        else input_error(move);
    }
}


void GameMgr::step()
{
    refresh_manager();
    std::cout << rndr_box->draw_view_of(plyr) << std::endl;
    react_box->list_nearby();
    mgr_ptr->step();
}


bool GameMgr::check_input(const char& ch)
{
    // Processing needed
    return true;
}


void GameMgr::input_error(const char& move)
{
    action_menu();
}