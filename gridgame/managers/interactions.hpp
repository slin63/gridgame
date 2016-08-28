//
//  interactions.hpp
//  gridgame
//
//  Created by SLIN63 on 8/27/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#ifndef interactions_hpp
#define interactions_hpp

#include "manager.hpp"
#include "player.hpp"

class InteractMgr
{
public:
    InteractMgr() = default;
    InteractMgr(Player*, Manager*);
    void list_nearby();
    
private:
    Player* plyr;
    Manager* mgr;
    
    std::vector<Manager::gVec> nearby_objs();
    Manager::gVec& objs_at_crds(const int&, const int&);
};

#endif /* interactions_hpp */
