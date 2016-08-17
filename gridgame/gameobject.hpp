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
    inline char get_symbol_raw() const;
    std::string get_symbol_colored() const;
    inline std::string get_color() const;
    void print();

    inline void set_symbol(const char&);
    inline void set_health(const int&);
    inline void set_color(const std::string&);

    inline void up(const int&);
    inline void down(const int&);
    inline void left(const int&);
    inline void right(const int&);

    void rand_walk(const int& d = 1);


protected:
    CRDS c;
    char symbol;
    int health;
    std::string color;
    bool draw = true;
};

extern const std::string colorless_ANSI;

CRDS GameObject::get_c() const { return c; }

char GameObject::get_symbol_raw() const { return symbol; }

std::string GameObject::get_color() const { return color; }

void GameObject::set_symbol(const char& sym) { symbol = sym; }

void GameObject::set_health(const int& hp) { health = hp; }

void GameObject::set_color(const std::string& ansi_code) { color = ansi_code; }

void GameObject::up(const int& d = 1) { c.delta(0, -d); }

void GameObject::down(const int& d = 1) { c.delta(0, d); }

void GameObject::right(const int& d = 1) { c.delta(d, 0); }

void GameObject::left(const int& d = 1) { c.delta(-d, 0); }


#endif /* gameobject_hpp */
