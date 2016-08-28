#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <vector>
#include "player.hpp"
#include "gameobject.hpp"
#include <map>


class Manager
{
public:
    Manager() = default;
    Manager(const int&, const int&);
    
    typedef std::vector<GameObject*> gVec;
    // rVec : y        -> x         -> contents at (x, y)
    typedef std::vector<std::vector<Manager::gVec>> rVec;
    
    inline gVec get_objects();
    inline void add(GameObject*);

    void step(); 
    
    void populate(const int&, const int&);
    
    inline int get_x(void) const;
    inline int get_y(void) const;
    inline rVec& get_r_grid(void);
    
    inline Player* get_player(void) const;
    
    static std::vector<CRDS> nearby(GameObject*, const int&);
    
    void player_up(void) const;
    void player_down(void) const;
    void player_left(void) const;
    void player_right(void) const;
    
    void assemble_rVec(void);

private:
    rVec r_grid;
    gVec objects;
    
    int HUMAN_LIMIT;
    int TREE_LIMIT;
    Player* player;
    
    GameObject* get_rand_obj(const gVec&);
    
    inline int get_rand_int(const int&);
    
    void populate_creature(const int&, const int&);
    
    void populate_static(const int&, const int&);
    
    template<typename T>
    void add_player(void);
    
    template<typename GameT>
    void populate_with_model(const int&, const int&, const int&);
    
    int max_x;
    int max_y;
};

Manager::rVec& Manager::get_r_grid(void) { return r_grid; }

int Manager::get_x(void) const { return max_x; }
int Manager::get_y(void) const { return max_y; }

Manager::gVec Manager::get_objects(void) { return objects; }

void Manager::add(GameObject* g_obj) { objects.push_back(g_obj); }

int Manager::get_rand_int(const int& i) { return rand() % i; }

Player* Manager::get_player(void) const { return player; }

#endif
