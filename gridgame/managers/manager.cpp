#include "manager.hpp"

#include "coordinates.hpp"
#include "tree.hpp"
#include "grass.hpp"
#include "human.hpp"
#include <typeinfo>

const int human_limit = 5;
const int tree_limit = 5;

GameObject Manager::get_rand_obj(const std::vector<GameObject>& gvec)
{
    size_t ch = rand() % gvec.size();
    return gvec[ch];
}

void Manager::populate_static(const int& x, const int& y)
{
    populate_with_model("tree", tree_limit, x, y);
    
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            CRDS coor(i, j);
            Grass grass(coor);
            add(grass);
        }
    }
}

void Manager::populate_with_model(const std::string& type, const int& limit, const int& x, const int& y)
{
    GameObject ret;
    if (type == "tree")
        ret = Tree();
    
    for (int i = 0; i < limit; ++i)
    {
        int x_n = get_rand_int(x);
        int y_n = get_rand_int(y);
        ret.set_coord(CRDS(x_n, y_n));
        add(ret);
    }
}

void Manager::populate_creature(const int &x, const int &y)
{
    //TODO
    ;
}

void Manager::populate(const int& x, const int& y)
{
    populate_static(x, y);
    populate_creature(x, y);
}

