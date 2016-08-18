#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <vector>
#include "gameobject.hpp"

class Manager
{
typedef std::vector<GameObject*> gVec;
public:
    Manager() = default;
    inline gVec get_objects();
    inline void add(GameObject);

    GameObject nearby(const GameObject&, const int& d = 3); // Not implemented - returns objects nearby to a GameObject

    void step(); // Not implemented - advances game world by one click

private:
    gVec objects;
};

Manager::gVec Manager::get_objects(void) { return objects; }

void Manager::add(GameObject g_obj) {
    objects.push_back(&g_obj);
}

#endif
