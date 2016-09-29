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
#include <map>

class InteractMgr
{
public:
    InteractMgr() = default;
    InteractMgr(Player*, Manager*);
    inline std::map<int, GameObject*> get_nearby_objs(void);
    void list_nearby();
    
    void step(const int& step_count);

    // Refreshes set of nearby interactible non player objects
    void refresh_nearby_objs(void);
    
private:
    Player* plyr;
    Manager* mgr;
    Manager::gVec nearby_obj_list;
    std::map<int, GameObject*> id2obj_map;
    
    // Returns objects within specified range of player
    std::vector<Manager::gVec> nearby_objs(const int& range = 1);
    
    static Manager::gVec compress_vector(const std::vector<Manager::gVec>&);
    
    bool is_nearby(GameObject*);
    void apply_nearby_behavior(GameObject*);
    
    // Returns object stack at passed coordinates
    Manager::gVec& objs_at_crds(const int&, const int&);
};

std::map<int, GameObject*> InteractMgr::get_nearby_objs(void) { return id2obj_map; }

#endif /* interactions_hpp */
