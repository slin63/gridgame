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
#include <sstream>


RenderBox::RenderBox(const Manager& mgr_n)
{
    mgr = mgr_n;
    
    
//    r_grid.resize(mgr_n.get_y());
//    for (auto&& i : r_grid)
//        i.resize(mgr_n.get_x());
//    
    assemble_rVec();
}


std::string RenderBox::draw_map()
{
    std::stringstream map;
    for(auto&& y_set : r_grid)
    {
        for(auto&& x_set : y_set)
        {
            const GameObject* best_draw = highest_draw(x_set);
            map << best_draw->get_symbol();
        }
        map << "\n";
    }
    return map.str();
}


std::string RenderBox::draw_view_of(GameObject* g_ptr)
{
    assemble_rVec();
    
    std::stringstream map;
    std::vector<CRDS> nearby_objs = nearby(g_ptr, g_ptr->get_vision());
    // First y coordinate, will use to see if we've moved onto a newline
    int current = 0;
    for(auto&& obj : nearby_objs)
    {
        const GameObject* other_obj = g_obj_at_crds(obj.get_x(), obj.get_y());
        // Adds newlines as we advance down to the next y level
        if (obj.get_y() != current)
        {
            current = obj.get_y();
            map << "\n";
        }
        if (obj.distance(g_ptr->get_c()) > g_ptr->get_light())
        {
//            std::cout << g_ptr->is_sneaky() << g_ptr->get_symbol() << std::endl;
            const Symbol* symb = other_obj->get_symbol_ptr();
            if (other_obj->is_sneaky())
                map << symb->draw_sneaky();
            else
                map << symb->draw_dark();
        }
        else
            map << draw_at(obj);
    }
    map << std::endl;
    return map.str();
}


const GameObject* RenderBox::g_obj_at_crds(const int& x, const int& y)
{
    Manager::gVec g_objs = objs_at_crds(x, y);
    return highest_draw(g_objs);
}

// Returns objects in a box around the passed g_ptr obj
std::vector<CRDS> RenderBox::nearby(GameObject* g_ptr, const int& dist)
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
    
    return nearby;
}

const Symbol* RenderBox::symb_ptr_at(const CRDS& crds)
{
    Manager::gVec objs = objs_at_crds(crds.get_x(), crds.get_y());
    const GameObject* g_obj = highest_draw(objs);
    return g_obj->get_symbol_ptr();
}

const std::string RenderBox::draw_at(const int& x, const int& y)
{
    Manager::gVec objs = objs_at_crds(x, y);
    std::string symbol = highest_draw(objs)->get_symbol();
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
        if (i->get_draw_prty() <= max)
        {
            max = i->get_draw_prty();
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
    r_grid.clear();
//    std::cout << mgr.get_y() << " " << mgr.get_x() << " " << r_grid.size();
    r_grid.resize(mgr.get_y());
    for (auto&& i : r_grid)
        i.resize(mgr.get_x());
    
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