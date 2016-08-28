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


RenderBox::RenderBox(Manager& mgr_n)
{
    mgr = mgr_n;
    mgr_n.assemble_rVec();
    r_grid = mgr_n.get_r_grid();
}


std::string RenderBox::draw_map()
{
    std::stringstream map;
    mgr.assemble_rVec();
    r_grid = mgr.get_r_grid();
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
    mgr.assemble_rVec();
    r_grid = mgr.get_r_grid();
    
    std::stringstream map;
    std::vector<CRDS> nearby_objs = Manager::nearby(g_ptr, g_ptr->get_vision());
    // First y coordinate, will use to see if we've moved onto a newline
    int current_y = 0;
    for(auto&& obj : nearby_objs)
    {
        const GameObject* other_obj = g_obj_at_crds(obj.get_x(), obj.get_y());
        // Adds newlines as we advance down to the next y level
        if (obj.get_y() != current_y)
        {
            current_y = obj.get_y();
            map << "\n";
        }
        if (obj.distance(g_ptr->get_c()) > g_ptr->get_light())
        {
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


//std::string RenderBox::add_borders(const std::string& box)
//{
//    size_t row_l = box.find("\n");
//    return "#TODO";
//}


const GameObject* RenderBox::g_obj_at_crds(const int& x, const int& y)
{
    Manager::gVec g_objs = objs_at_crds(x, y);
    return highest_draw(g_objs);
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