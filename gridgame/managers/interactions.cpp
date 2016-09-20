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


void InteractMgr::refresh_nearby_objs()
{
    Manager::gVec near = compress_vector(nearby_objs());
    std::map<int, GameObject*> menu;
    size_t id = 0;
    
    for (auto&& i : near)
    {
        if (i->is_interactive() && !i->is_player())
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
//    std::cout << "Object at " << x << ", " << y << std::endl;
    return mgr->get_r_grid().at(y).at(x);
}