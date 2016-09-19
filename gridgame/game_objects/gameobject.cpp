//
//  gameobject.cpp
//  gridgame
//
//  Created by SLIN63 on 8/14/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#include "gameobject.hpp"
#include <sstream>
#include <iostream>


void GameObject::step(void) {;}

void GameObject::check_alive(void)
{
    if (health <= 0)
        alive = false;
}

void GameObject::attack(GameObject* other_ptr, const int& dmg)
{
    other_ptr->delta_health(dmg);
}

char GameObject::choose_random(const std::vector<char>& c_v)
{
    size_t ch = rand() % c_v.size();
    return c_v[ch];
}

GameObject::GameObject(const CRDS& coords) {
    c = coords;
}


void GameObject::print(void) {
    std::stringstream output;
    output << "CRDS: <" << c.get_x() << "," << c.get_y() << "> | ";
    output << "SYMB: '" << symbol->draw_symbol() << "' | HEALTH: " << health << std::endl;
    std::cout << output.str();
}


void GameObject::up(const int& d)
{
    if (get_c_y() - 1 >= 0)
        c.delta(0, -d);
}

void GameObject::down(const int& d)
{
    if (get_c_y() + 1 <= GLOBAL_Y - 1)
        c.delta(0, d);
}

void GameObject::right(const int& d)
{
    if (get_c_x() + 1 <= GLOBAL_X - 1)
        c.delta(d, 0);
}

void GameObject::left(const int& d)
{
    if (get_c_x() - 1 >= 0)
        c.delta(-d, 0);
}


const std::string colorless_ANSI = "\033[0m";
