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
    
    inline size_t get_step();
    
private:
    Manager* mgr_ptr;
    RenderBox* rndr_box;
    InteractMgr* react_box;
    GameObject* plyr;
    
    size_t step_count = 0;
    
    void help_menu(void);
    
    void attack_menu(void);
    
    
    // Make sure user didn't mess up
    bool check_input(char&);
    void input_error(const char&);
    void refresh_manager(void) { mgr_ptr->assemble_rVec(); }
    void refresh_react_box(void) { react_box->refresh_nearby_objs(); }
    
    void step();
};

size_t GameMgr::get_step(void) { return step_count; }

#endif /* gamemgr_hpp */
