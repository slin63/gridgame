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
    symb = sym;
    color = clr;
    effect = efct;
    background = bg;
}


Symbol::Symbol(const char& sym)
{
    symb = sym;
}


std::string Symbol::draw_symbol(const Effect& COLOR, const Effect& EFFECT, const Effect& BACKGROUND)
{
    std::stringstream s;
    s   << "\033[" << EFFECT << "m"
        << "\033[" << COLOR << "m"
        << "\033[" << BACKGROUND << "m"
        << symb
        << reset_style;
    return s.str();
}


std::string Symbol::draw_symbol(void)
{
    return draw_symbol(color, effect, background);
}


std::string Symbol::draw_dark(void) const
{
    std::stringstream s;
    s   << "\033[" << Effect::DIM << "m"
        << "\033[" << Effect::BLUE << "m"
        << symb
        << reset_style;
    return s.str();
}


std::string Symbol::draw_sneaky(void) const
{
    std::stringstream s;
    s   << "\033[" << Effect::DIM << "m"
        << "\033[" << Effect::RED << "m"
        << '!'
        << reset_style;
    return s.str();
}