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
    
    std::cout << rndr_box->draw_view_of(plyr) << std::endl;
    
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
            else if (move == 'h')
                help_menu();
            else if (move == 'k')
                attack_menu();
            step();
        }
        else input_error(move);
    }
}


void GameMgr::help_menu()
{
    std::cout << "k: Attack Something\nE: Exit" << std::endl;
    char choice;
    std::cin >> choice;
}


void GameMgr::attack_menu()
{
    std::cout << "Enter the number corresponding to your target!" <<std::endl;
    react_box->list_nearby();
    
    int target_id;
    std::cin >> target_id;
    GameObject* target = react_box->get_nearby_objs()[target_id];
    
    plyr->attack(target, plyr->get_strength());
}


void GameMgr::step()
{
    ++step_count;
    refresh_manager();
    refresh_react_box();
    std::cout << step_count << std::endl;
    std::cout << rndr_box->draw_view_of(plyr) << std::endl;
    react_box->step(step_count);
}


bool GameMgr::check_input(char& ch)
{
    // Processing needed
    ch = tolower(ch);
    return true;
}


void GameMgr::input_error(const char& move)
{
    action_menu();
}