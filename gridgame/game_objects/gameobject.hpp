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
#include "behavior.hpp"
#include <vector>
#include <string>
#include <cstdlib>


// On step: Check if alive (health > 0)
// If dead, set bg to red or whatever, remove "alive" step function components

class GameObject {
public:
    GameObject() = default;
    GameObject(const CRDS&);
    inline CRDS get_c() const;
    inline int get_strength() const;
    inline std::string get_name() const;
    inline std::string get_death_msg() const;
    inline int get_c_x() const;
    inline int get_c_y() const;
    inline int get_health() const;
    inline int get_vision() const;
    inline int get_speed() const;
    inline double get_distance_to(GameObject*) const;
    inline Symbol* get_symbol_ptr() const;
    inline int get_light() const;
    inline int get_draw_prty() const;
    inline bool is_sneaky() const;
    inline bool is_alive() const;
    inline bool is_interactive() const;
    inline bool is_hostile() const;
    inline bool is_wanderer() const;
    inline bool is_ready(const int&) const;
    inline bool should_draw() const;
    inline std::string get_symbol() const;
    
    void print();
    
    // Interactions
    // Define object attack method here
    virtual void attack(GameObject*, const int&);
    
    // Define per-turn actions here
    virtual void step();
    virtual void check_alive();

    inline void delta_health(const int&);
    inline void set_health(const int&);
    inline void set_strength(const int&);
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
    std::string name = "Game Object";
    
    char dead_symbol;
    Symbol::Effect dead_color = Symbol::Effect::RED_BG;
    std::string death_msg = "has been slain!";
    
    int health;
    
    // No. of steps before an action is performed
    int speed = 2;
    
    bool player = false;
    bool draw = true;
    bool hides_in_shadows = false;
    bool can_interact = true;
    bool hostile = false;
    bool wanders = false;
    
    bool alive = true;
    
    int strength = 15;
    double accuracy = 0.9;
    int draw_priority = 10;
    int vision_range = 10;
    int light_range = 5;
};


void GameObject::wait(void) { ; }

int GameObject::get_c_x() const { return c.get_x(); }
int GameObject::get_c_y() const { return c.get_y(); }

bool GameObject::is_interactive() const { return can_interact; }

bool GameObject::is_alive() const { return alive; }

bool GameObject::is_ready(const int& step) const { return ( (step % speed) == 0); }

bool GameObject::is_hostile() const { return hostile; }

bool GameObject::is_wanderer() const { return wanders; }

int GameObject::get_speed() const { return speed; }

bool GameObject::is_sneaky() const { return hides_in_shadows; }

int GameObject::get_vision() const { return vision_range; }

std::string GameObject::get_name() const { return name; }

std::string GameObject::get_death_msg() const { return death_msg; }

double GameObject::get_distance_to(GameObject* other) const { return c.distance(other->get_c()); }

int GameObject::get_strength() const { return strength; }

int GameObject::get_health() const { return health; }

int GameObject::get_light() const { return light_range; }

Symbol* GameObject::get_symbol_ptr() const { return symbol; }

void GameObject::set_coord(const CRDS& c_n) { c = c_n; }

CRDS GameObject::get_c() const { return c; }

std::string GameObject::get_symbol() const { return symbol->draw_symbol(); }

int GameObject::get_draw_prty() const { return draw_priority; }

bool GameObject::should_draw() const { return draw; }

void GameObject::set_player(const bool& b) { player = b; }

void GameObject::set_symbol(const char& c) { symbol->set_symbol(c); }

void GameObject::delta_health(const int & i) { health += i; }

void GameObject::set_health(const int& hp) { health = hp; }

void GameObject::set_strength(const int& str) { strength = str; }

void GameObject::set_draw_prty(const int& i) { draw_priority = i; }

void GameObject::set_draw_bool(const bool& i) { draw = i; }

const bool& GameObject::is_player(void) { return player; }

#endif /* gameobject_hpp */
