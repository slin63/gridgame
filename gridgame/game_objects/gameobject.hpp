//
//  gameobject.hpp
//  gridgame
//
//  Created by SLIN63 on 8/14/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "coordinates.hpp"
#include "symbol.hpp"
#include "constants.hpp"
#include <vector>
#include <string>
#include <cstdlib>


class GameObject {
public:
    GameObject() = default;
    GameObject(const CRDS&);
    inline CRDS get_c() const;
    inline int get_c_x() const;
    inline int get_c_y() const;
    inline int get_vision() const;
    inline Symbol* get_symbol_ptr() const;
    inline int get_light() const;
    inline int get_draw_prty() const;
    inline bool is_sneaky() const;
    inline bool is_interactive() const;
    inline bool should_draw() const;
    inline std::string get_symbol() const;
    
    void print();
    
    // Virtual tag to enable polymorphism
    virtual void step();

    inline void set_health(const int&);
    inline void set_coord(const CRDS&);
    inline void set_draw_prty(const int&);
    inline void set_draw_bool(const bool&);
    inline void set_player(const bool&);
    inline void set_symbol(const char&);
    
    void up(const int& d = 1);
    void down(const int& d = 1);
    void left(const int& d = 1);
    void right(const int& d = 1);
    inline void wait(void);
    
    inline const bool& is_player(void);

private:
    char choose_random(const std::vector<char>&);
    
protected:
    CRDS c;
    Symbol* symbol = new Symbol();
    int health;
    bool player = false;
    bool draw = true;
    bool hides_in_shadows = false;
    bool can_interact = true;
    int draw_priority = 10;
    int vision_range = 10;
    int light_range = 5;
};


void GameObject::wait(void) { ; }

int GameObject::get_c_x() const { return c.get_x(); }
int GameObject::get_c_y() const { return c.get_y(); }

bool GameObject::is_interactive() const { return can_interact; }

bool GameObject::is_sneaky() const { return hides_in_shadows; }

int GameObject::get_vision() const { return vision_range; }

int GameObject::get_light() const { return light_range; }

Symbol* GameObject::get_symbol_ptr() const { return symbol; }

void GameObject::set_coord(const CRDS& c_n) { c = c_n; }

CRDS GameObject::get_c() const { return c; }

std::string GameObject::get_symbol() const { return symbol->draw_symbol(); }

int GameObject::get_draw_prty() const { return draw_priority; }

bool GameObject::should_draw() const { return draw; }

void GameObject::set_player(const bool& b) { player = b; }

void GameObject::set_symbol(const char& c) { symbol->set_symbol(c); }

void GameObject::set_health(const int& hp) { health = hp; }

void GameObject::set_draw_prty(const int& i) { draw_priority = i; }

void GameObject::set_draw_bool(const bool& i) { draw = i; }

const bool& GameObject::is_player(void) { return player; }

#endif /* gameobject_hpp */
