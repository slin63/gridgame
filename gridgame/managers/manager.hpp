#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <vector>
#include "gameobject.hpp"
#include <map>

class Manager
{
typedef std::vector<GameObject> gVec;
    
public:
    Manager() = default;
    inline gVec get_objects();
    inline void add(GameObject);

    GameObject nearby(const GameObject&, const int& d = 3); // Not implemented - returns objects nearby to a GameObject

    void step(); // Not implemented - advances game world by one click
    void populate(const int&, const int&); // Not implemented - calls populate_static then populate_creature
    
private:
    gVec objects;
    GameObject get_rand_obj(const std::vector<GameObject>&);
    inline int get_rand_int(const int&);
    void populate_creature(const int&, const int&);
    void populate_static(const int&, const int&); // Not implemented - Fills grid with random statics
    void populate_with_model(const std::string&, const int&, const int&, const int&);
};

// Percent of map we can assign to each type
extern const int human_limit;
extern const int tree_limit;

Manager::gVec Manager::get_objects(void) { return objects; }

void Manager::add(GameObject g_obj) { objects.push_back(g_obj); }

int Manager::get_rand_int(const int& i) { return rand() % i; }


#endif
