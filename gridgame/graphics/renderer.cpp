//
//  renderer.cpp
//  gridgame
//
//  Created by SLIN63 on 8/15/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#include "renderer.hpp"
#include <iostream>
#include <algorithm>


RenderBox::RenderBox(const Manager& mgr_n)
{
    mgr = mgr_n;
    
    r_grid.resize(mgr_n.get_y());
    for (auto&& i : r_grid)
        i.resize(mgr_n.get_x());
    
    assemble_rVec();
    nearby_square(mgr_n.get_player()->get_avatar(), 500);
}

// Returns objects in a box around the passed g_ptr obj
std::vector<CRDS> RenderBox::nearby_square(GameObject* g_ptr, const int& dist)
{
    const CRDS c = g_ptr->get_c();
    std::vector<CRDS> nearby;
    
    int x_min = c.get_x() - dist;
    int x_max = c.get_x() + dist;
    // Remember, the larger the y value the lower it is
    int y_min = c.get_y() - dist;
    int y_max = c.get_y() + dist;
    
    // Making sure values are in range
    if (x_min < 0) { x_min = 0; }
    if (y_min < 0) { y_min = 0; }
    if (x_max > mgr.get_x()) { x_max = mgr.get_x(); }
    if (y_max > mgr.get_y()) { y_max = mgr.get_y(); }
    
    
    for (int y = y_min; y < y_max; ++y)
    {
        for (int x = x_min; x < x_max; ++x)
        {
            nearby.push_back(CRDS(x, y));
        }
    }
    
    for (auto&& i : nearby)
        std::cout << i.get_x() << " " << i.get_y() << std::endl;
    return nearby;
}

// Returns CRDS within a radius around passed g_ptr
std::vector<CRDS> nearby_radius(const std::vector<CRDS>& c_vec, GameObject* g_ptr, const int& radi)
{
    const CRDS c = g_ptr->get_c();
    std::vector<CRDS> in_radius;
    
    for (auto&& crd : c_vec)
    {
        if (crd.distance(c) <= radi) {
            in_radius.push_back(crd);
        }
    }
    
    return in_radius;
}


const std::string RenderBox::draw_at(const int& x, const int& y)
{
    Manager::gVec objs = objs_at_crds(x, y);
    std::string symbol = highest_draw(objs)->get_symbol_colored();
    return symbol;
}

const std::string RenderBox::draw_at(const CRDS& crd)
{
    return draw_at(crd.get_x(), crd.get_y());
}


const GameObject* RenderBox::highest_draw(const Manager::gVec& v)
{
    GameObject* ret = nullptr;
    int max = 10;
    // 1 = Definitely draw, 5 = Draw after (1 through 4) have been drawn
    for (auto&& i : v)
    {
        if (i->get_draw_prty() < max)
        {
            max = i->get_draw_prty();
            ret = i;
        }
        // To handle cases where two objects have the same draw priority
        else if (i->get_draw_prty() == max)
        {
            if ((rand() % 2) == 1)
                ret = i;
        }
    }
    return ret;
}


const Manager::gVec& RenderBox::objs_at_crds(const int& x, const int& y)
{
    return r_grid.at(y).at(x);
}


void RenderBox::list_elements(void)
{
    Manager::gVec objs = mgr.get_objects();
    for (auto&& obj : objs)
        obj->print();
}


bool crdsSmallerX(const GameObject* g1, const GameObject* g2)
{
    return (g1->get_c_x() < g2->get_c_x());
}


bool crdsSmallerY(const GameObject* g1, const GameObject* g2)
{
    return (g1->get_c_y() < g2->get_c_y());
}


void RenderBox::assemble_rVec(void)
{
    for (auto&& ptr : mgr.get_objects())
    {
        r_grid.at(ptr->get_c_y()).at(ptr->get_c_x()).push_back(ptr);
    }
}


void RenderBox::sort_crds(Manager::gVec& v)
{
    std::sort(v.begin(), v.end(), crdsSmallerX);
}


// Debugging
template <typename T>
void RenderBox::list_contents(const T& v)
{
    for (auto&& i : v)
        std::cout << i.get_x() << std::endl;
//        std::cout << i->get_symbol_raw() << std::endl;
}