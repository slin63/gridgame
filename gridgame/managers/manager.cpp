#include "manager.hpp"
#include "coordinates.hpp"
#include "tree.hpp"
#include "grass.hpp"
#include "human.hpp"
#include "goblin.hpp"
#include "constants.hpp"
#include <exception>

//void Manager::step(void)
//{
//    for (auto&& i : objects)
//        i->step();
//}


Manager::Manager(const int& x, const int& y)
{
//    if(x > 100)
//        throw std::range_error("X dimension too large for clean render");
    int area = x * y;
    HUMAN_LIMIT = area * HUMAN_PCT;
    TREE_LIMIT = area * TREE_PCT;
    GOBLIN_LIMIT = area * GOBLIN_PCT;
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
    populate_with_model<Goblin>(GOBLIN_LIMIT, x, y);
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


void Manager::assemble_rVec(void)
{
    rVec r_grid_buffer;
    r_grid_buffer.resize(GLOBAL_Y);
    for (auto&& i : r_grid_buffer)
        i.resize(GLOBAL_X);
    
    for (auto&& ptr : objects)
    {
        r_grid_buffer.at(ptr->get_c_y()).at(ptr->get_c_x()).push_back(ptr);
    }
    
    r_grid = r_grid_buffer;
}


// Returns objects in a box around the passed g_ptr obj
std::vector<CRDS> Manager::nearby(GameObject* g_ptr, const int& dist)
{
    const CRDS c = g_ptr->get_c();
    std::vector<CRDS> nearby;
    
    int x_min = c.get_x() - dist;
    int x_max = c.get_x() + dist;
    // Remember, the larger the y value the lower it is
    int y_min = c.get_y() - dist;
    int y_max = c.get_y() + dist;
    
    // Making sure values are in range
    if (x_min < 0) { x_min = 0; }
    if (y_min < 0) { y_min = 0; }
    if (x_max > GLOBAL_X) { x_max = GLOBAL_X; }
    if (y_max > GLOBAL_Y) { y_max = GLOBAL_Y; }
    
    
    
    for (int y = y_min; y != y_max + 1; ++y)
    {
        for (int x = x_min; x != x_max + 1; ++x)
        {
            if (x == GLOBAL_X || y == GLOBAL_Y)
                continue;
            else
                nearby.push_back(CRDS(x, y));
            
        }
    }
    return nearby;
}


template<typename T>
void Manager::add_player(void)
{
    CRDS c(GLOBAL_X / 2, 0); // Placeholder
    T* avatar = new T(c);
    player = new Player(avatar);
    avatar->set_player(true);
    avatar->set_coord(c);
    avatar->get_symbol_ptr()->set_symbol('U');
    avatar->get_symbol_ptr()->set_effect(Symbol::UNDERLINED);
    avatar->get_symbol_ptr()->set_color(Symbol::YELLOW);
    avatar->set_health(50);
    avatar->set_strength(25);
    add(avatar);
}


void Manager::player_up(void) const
{
    GameObject* plyr = get_player()->get_avatar();
    if (plyr->get_c_y() - 1 >= 0)
        plyr->up();
}

void Manager::player_down(void) const
{
    GameObject* plyr = get_player()->get_avatar();
    if (plyr->get_c_y() + 1 <= max_y)
        plyr->down();
}

void Manager::player_left(void) const
{
    GameObject* plyr = get_player()->get_avatar();
    if (plyr->get_c_x() - 1 <= 0)
        plyr->left();
}

void Manager::player_right(void) const
{
    GameObject* plyr = get_player()->get_avatar();
    if (plyr->get_c_x() + 1 <= max_x)
        plyr->right();
}



