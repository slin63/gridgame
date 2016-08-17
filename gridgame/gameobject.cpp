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



GameObject::GameObject(const CRDS& coords) {
    c = coords;
}

void GameObject::print(void) {
    std::stringstream output;
    output << "CRDS: <" << c.get_x() << "," << c.get_y() << "> | ";
    output << "SYMB: '" << get_symbol_colored() << "' | HEALTH: " << health << std::endl;
    std::cout << output.str();
}

std::string GameObject::get_symbol_colored() const {
    std::stringstream colored;
    colored << color << symbol << colorless_ANSI;
    return colored.str();
}

void GameObject::rand_walk(const int& d)
{


    int ch = rand() % 4;
    switch(ch)
    {
        case 0 : up(d);
                break;
        case 1 : down(d);
                break;
        case 2 : left(d);
                break;
        case 3 : right(d);
                break;
    }
}


const std::string colorless_ANSI = "\033[0m";
