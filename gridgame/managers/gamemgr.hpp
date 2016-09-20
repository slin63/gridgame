//
//  gamemgr.hpp
//  gridgame
//
//  Created by SLIN63 on 8/30/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#ifndef gamemgr_hpp
#define gamemgr_hpp

#include <stdio.h>

#include "manager.hpp"
#include "renderer.hpp"
#include "interactions.hpp"

class GameMgr
{
public:
    GameMgr();
    void action_menu(void);
    
private:
    Manager* mgr_ptr;
    RenderBox* rndr_box;
    InteractMgr* react_box;
    GameObject* plyr;
    
    void help_menu(void);
    
    void attack_menu(void);
    void report_attack(GameObject*, GameObject*, const int&);
    
    // Make sure user didn't fuck up
    bool check_input(const char&);
    void input_error(const char&);
    void refresh_manager(void) { mgr_ptr->assemble_rVec(); }
    void refresh_react_box(void) { react_box->refresh_nearby_objs(); }
    
    void step();
};


#endif /* gamemgr_hpp */
