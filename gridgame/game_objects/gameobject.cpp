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


void GameObject::step() {;}


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


const std::string colorless_ANSI = "\033[0m";
