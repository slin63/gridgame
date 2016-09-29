//
//  interactions.cpp
//  gridgame
//
//  Created by SLIN63 on 8/27/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#include "interactions.hpp"
#include <iostream>
//#include <map>


InteractMgr::InteractMgr(Player* plyr_n, Manager* mgr_n)
{
    plyr = plyr_n;
    mgr = mgr_n;
};


Manager::gVec InteractMgr::compress_vector(const std::vector<Manager::gVec>& fat_v)
{
    Manager::gVec ret_v;
    
    for (auto&& i : fat_v)
    {
        for (auto&& j : i)
        {
            ret_v.push_back(j);
        }
    }
    
    return ret_v;
}

// http://stackoverflow.com/questions/3450860/check-if-a-stdvector-contains-a-certain-object
void InteractMgr::step(const int& step_count)
{
    for (auto&& obj : mgr->get_objects())
    {
        obj->step();
        if ( obj->is_ready(step_count) )
            apply_nearby_behavior(obj);
    }
}


void InteractMgr::apply_nearby_behavior(GameObject* obj)
{
    int interact_range = plyr->get_avatar()->get_vision() * 1.5;
    GameObject* plyr_char = plyr->get_avatar();
    bool in_range = ( obj->get_distance_to(plyr_char) <= interact_range );
    
    if (in_range && !obj->is_player() && obj->is_alive())
    {
        // obj.apply_nearby_behavior() - > to be implemented
        if (obj->is_hostile())
            BehaviorBox::chase(obj, plyr->get_avatar(), true);
        else if (obj->is_wanderer() && !obj->is_hostile())
        {
            BehaviorBox::rand_walk(1, obj);
        }
    }
}


void InteractMgr::refresh_nearby_objs()
{
    int plyr_vision = plyr->get_avatar()->get_vision();
    GameObject* plyr_char = plyr->get_avatar();
    
    nearby_obj_list = compress_vector(nearby_objs(plyr_vision));
    std::map<int, GameObject*> menu;
    size_t id = 0;
    
    // Populating the id to object map for interaction menus later
    for (auto&& i : nearby_obj_list)
    {
        if (i->is_interactive() && !i->is_player() && i->get_distance_to(plyr_char) < 1.42)
        {
            menu[id] = i;
            ++id;
        }
    }
    
    id2obj_map = menu;
}


void InteractMgr::list_nearby()
{
    for (auto&& i : id2obj_map)
    {
        std::cout << i.first << ": ";
        i.second->print();
    }
}


std::vector<Manager::gVec> InteractMgr::nearby_objs(const int& range)
{
    std::vector<CRDS> near_crds = Manager::nearby(plyr->get_avatar(), range);
    std::vector<Manager::gVec> nearby_objs;
    
    
    for(auto&& tile : near_crds)
    {
        nearby_objs.push_back(objs_at_crds(tile.get_x(), tile.get_y()));
    }
    
    return nearby_objs;
}


Manager::gVec& InteractMgr::objs_at_crds(const int& x, const int& y)
{
    return mgr->get_r_grid().at(y).at(x);
}


bool InteractMgr::is_nearby(GameObject* g_ptr)
{
    for (auto&& obj : id2obj_map)
    {
        if (obj.second == g_ptr) {
            return true;
        }
    }
    return false;
}









