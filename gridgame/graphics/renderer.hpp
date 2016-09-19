//
//  renderer.hpp
//  gridgame
//
//  Created by SLIN63 on 8/15/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//
// http://en.cppreference.com/w/cpp/io/manip
// Rendering is flawed: We can't sort items into 2d vectors if we're going be updating their locations. Fix this!
// --- Populate a 2d vector at render time and then draw it without needing to order it.


#ifndef renderer_hpp
#define renderer_hpp

#include "manager.hpp"
#include "symbol.hpp"
class Player;

class RenderBox {
public:
    RenderBox() = default;
    RenderBox(Manager*);
    void list_elements();
    std::string draw_map();
    std::string draw_player_view(); // Calls draw_view_of with player G.O.
    std::string draw_view_of(GameObject*);
    
private:
    Manager* mgr;
    Manager::rVec r_grid;
    
    // Draw accessories
    // NOT IMPLEMENTED
    std::string add_borders(const std::string&);
    
    // Draw logic
    const std::string draw_at(const int&, const int&);
    const std::string draw_at(const CRDS&);
    const GameObject* highest_draw(const Manager::gVec&);
    const Manager::gVec& objs_at_crds(const int&, const int&);
    const Symbol* symb_ptr_at(const CRDS&);
    const GameObject* g_obj_at_crds(const int&, const int&);
    
    void sort_crds(Manager::gVec&);
    
    // Debugging
    template <typename T>
    void list_contents(const T&);
};





#endif /* renderer_hpp */
