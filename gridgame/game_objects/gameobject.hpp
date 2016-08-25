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
#include <string>
#include <cstdlib>

class GameObject {
public:
    GameObject() = default;
    GameObject(const CRDS&);
    inline CRDS get_c() const;
    inline int get_c_x() const;
    inline int get_c_y() const;
    inline int get_draw_prty() const;
    inline char get_symbol_raw() const;
    inline bool should_draw() const;
    std::string get_symbol_colored() const;
    inline std::string get_color() const;
    void print();
    
    // Virtual tag to enable polymorphism
    virtual void step();

    inline void set_symbol(const char&);
    inline void set_health(const int&);
    inline void set_color(const std::string&);
    inline void set_coord(const CRDS&);
    inline void set_draw_prty(const int&);
    inline void set_draw_bool(const bool&);
    inline void set_player(const bool&);
    
    inline const bool& is_player(void);

protected:
    CRDS c;
    char symbol;
    int health;
    bool player = false;
    bool draw = true;
    int draw_priority = 10;
    std::string color;
};

inline int GameObject::get_c_x() const { return c.get_x(); }
inline int GameObject::get_c_y() const { return c.get_y(); }

extern const std::string colorless_ANSI;

void GameObject::set_coord(const CRDS& c_n) { c = c_n; }

CRDS GameObject::get_c() const { return c; }

char GameObject::get_symbol_raw() const { return symbol; }

int GameObject::get_draw_prty() const { return draw_priority; }

bool GameObject::should_draw() const { return draw; }

std::string GameObject::get_color() const { return color; }

void GameObject::set_symbol(const char& sym) { symbol = sym; }

void GameObject::set_player(const bool& b) { player = b; }

void GameObject::set_health(const int& hp) { health = hp; }

void GameObject::set_color(const std::string& ansi_code) { color = ansi_code; }

void GameObject::set_draw_prty(const int& i) { draw_priority = i; }

void GameObject::set_draw_bool(const bool& i) { draw = i; }

const bool& GameObject::is_player(void) { return player; }

#endif /* gameobject_hpp */
