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
    int damage = -(rand() % plyr->get_strength());
    
    plyr->attack(target, damage);
    report_attack(plyr, target, damage);
}


void GameMgr::report_attack(GameObject* attacker, GameObject* victim, const int& dmg)
{
    std::string attacker_name = attacker->get_name();
    std::string victim_name = victim->get_name();
    
    std::cout << attacker_name << " dealt " << -dmg << " damage to " << victim_name << "!" << std::endl;
    if (!victim->is_alive() || victim->get_health() <= 0)
    {
        std::cout << victim_name << " " << victim->get_death_msg() << std::endl;
    }
    else
    {
        std::cout << victim_name << " has " << victim->get_health() << " HP remaining. " << std::endl;
    }
}



void GameMgr::step()
{
    refresh_manager();
    refresh_react_box();
    
    std::cout << rndr_box->draw_view_of(plyr) << std::endl;
//    react_box->list_nearby();
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