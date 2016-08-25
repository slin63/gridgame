//
//  symbol.cpp
//  gridgame
//
//  Created by SLIN63 on 8/25/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#include "symbol.hpp"
#include <sstream>
#include <iostream>


Symbol::Symbol(const char& sym, const Effect& clr, const Effect& efct, const Effect& bg)
{
    symbol = sym;
    color = clr;
    effect = efct;
    background = bg;
}


Symbol::Symbol(const char& sym)
{
    symbol = sym;
}


void Symbol::draw_symbol(const Effect& COLOR, const Effect& EFFECT, const Effect& BACKGROUND)
{
    std::stringstream s;
    s   << "\033[" << EFFECT << "m"
        << "\033[" << COLOR << "m"
        << "\033[" << BACKGROUND << "m"
        << symbol
        << reset_style;
    std::cout << s.str();
}


void Symbol::draw_symbol(void)
{
    return draw_symbol(color, effect, background);
}


void Symbol::draw_dark(void)
{
    std::stringstream s;
    s   << "\033[" << Effect::DIM << "m"
        << '!'
        << reset_style;
    std::cout << s.str();
}