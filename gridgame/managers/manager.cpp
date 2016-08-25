#include "manager.hpp"

#include "coordinates.hpp"
#include "tree.hpp"
#include "grass.hpp"
#include "human.hpp"
#include <typeinfo>


void Manager::step(void)
{
    for (auto&& i : objects)
        i->step();
}


Manager::Manager(const int& x, const int& y)
{
    int area = x * y;
    HUMAN_LIMIT = area * 0.5;
    TREE_LIMIT = area * 0.5;
    populate(x, y);
    max_x = x;
    max_y = y;
}


GameObject* Manager::get_rand_obj(const std::vector<GameObject*>& gvec)
{
    size_t ch = rand() % gvec.size();
    return gvec[ch];
}


void Manager::populate(const int& x, const int& y)
{
    populate_static(x, y);
    populate_creature(x, y);
    add_player<Human>();
}


void Manager::populate_static(const int& x, const int& y)
{
    // Add static models
    populate_with_model<Tree>(TREE_LIMIT, x, y);
    
    // For base-tile (currently grass 8-16-2016)
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            CRDS coor(i, j);
            Grass* grass = new Grass(coor);
            add(grass);
        }
    }
}


void Manager::populate_creature(const int &x, const int &y)
{
    populate_with_model<Human>(HUMAN_LIMIT, x, y);
}


template<typename GameT>
void Manager::populate_with_model(const int& limit, const int& x, const int& y)
{
    GameObject* ret = nullptr;
    for (int i = 0; i < limit; ++i)
    {
        int x_n = get_rand_int(x);
        int y_n = get_rand_int(y);
        CRDS c = CRDS(x_n, y_n);
        ret = new GameT(c);
        add(ret);
    }
}

template<typename T>
void Manager::add_player(void)
{
    CRDS c(0,0); // Placeholder
    T* avatar = new T(c);
    player = new Player(avatar);
    avatar->set_player(true);
    avatar->set_symbol('U');
    add(avatar);
}

