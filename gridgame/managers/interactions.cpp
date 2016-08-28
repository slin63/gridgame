//
//  interactions.cpp
//  gridgame
//
//  Created by SLIN63 on 8/27/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#include "interactions.hpp"
#include <iostream>


InteractMgr::InteractMgr(Player* plyr_n, Manager* mgr_n)
{
    plyr = plyr_n;
    mgr = mgr_n;
};


void InteractMgr::list_nearby()
{
    std::vector<Manager::gVec> near = nearby_objs();
    std::cout << "Nearby: " << std::endl;
    for (auto&& i : near)
    {
        for (auto&& j : i)
        {
            if (j->is_interactive())
            {
                std::cout << "    ";
                j->print();
            }
        }
    }
}


std::vector<Manager::gVec> InteractMgr::nearby_objs()
{
    std::vector<CRDS> near_crds = Manager::nearby(plyr->get_avatar(), 1);
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