//
//  renderer.hpp
//  gridgame
//
//  Created by SLIN63 on 8/15/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//
// http://en.cppreference.com/w/cpp/io/manip

#ifndef renderer_hpp
#define renderer_hpp

#include "manager.hpp"
class Player;

class RenderBox {
public:
    // rVec : y        -> x         -> contents at (x, y)
    typedef std::vector<std::vector<Manager::gVec>> rVec;
    RenderBox() = default;
    RenderBox(const Manager&);
    void list_elements();

private:
    // Constructors
    Manager mgr;
    rVec r_grid;
    void assemble_rVec(void);
    
    // Draw logic
    const std::string draw_at(const int&, const int&);
    const std::string draw_at(const CRDS&);
    const GameObject* highest_draw(const Manager::gVec&);
    const Manager::gVec& objs_at_crds(const int&, const int&);
    
    // Nearby -> Get objects -> Renderer - - > Renderer checks if in radius, if not apply gray/dimming effect to symbol -> Render
    // Out of light radius: Give non-static entities the '!' char, remove bg effects
    std::vector<CRDS> nearby_square(GameObject*, const int&);
    
    // Probably not necessary
    std::vector<CRDS> nearby_radius(const std::vector<CRDS>&, GameObject*, const int&);
    
    void sort_crds(Manager::gVec&);
    
    // Debugging
    template <typename T>
    void list_contents(const T&);
};





#endif /* renderer_hpp */
