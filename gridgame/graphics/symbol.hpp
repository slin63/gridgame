//
//  symbol.hpp
//  gridgame
//
//  Created by SLIN63 on 8/25/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#ifndef symbol_hpp
#define symbol_hpp

#include "string"

class Symbol {
public:
    // http://misc.flogisoft.com/bash/tip_colors_and_formatting
    enum Effect
    {
        // EFFECTS
        BLANK = 0,
        BOLD = 1,
        DIM = 2,
        UNDERLINED = 4,
        REVERSE = 7,
        HIDDEN = 8,
        BLINK = 5, // doesn't work on most terminals
        
        // COLORS
        BLACK = 30,
        RED = 31,
        GREEN = 32,
        YELLOW = 33,
        BLUE = 34,
        MAGENTA = 35,
        CYAN = 36,
        WHITE = 37,
        DEFAULT = 39,
        
        // Background colors
        DEFAULT_BG = 49,
        BLACK_BG = 40,
        RED_BG = 41,
        GREEN_BG = 42,
        YELLOW_BG = 43,
        BLUE_BG = 44,
        MAGENTA_BG = 45
    };
    
    Symbol() = default;
    Symbol(const char&);
    Symbol(const char&, const Effect&, const Effect&, const Effect&);
    
    inline void set_symbol(const char&);
    inline void set_color(const Effect&);
    inline void set_effect(const Effect&);
    inline void set_background(const Effect&);
    
    std::string draw_symbol(const Effect&, const Effect&, const Effect&);
    std::string draw_symbol(void);
    
    std::string draw_dark(void) const;
    
    std::string draw_sneaky(void) const;
    
    
private:
    char symb = '?';
    Effect color = DEFAULT;
    Effect effect = DEFAULT;
    Effect background = DEFAULT_BG;
    const std::string reset_style = "\033[0m";
    
};

void Symbol::set_symbol(const char& sym_n) { symb = sym_n; }

void Symbol::set_effect(const Effect& efct_n) { effect = efct_n; }

void Symbol::set_color(const Effect & clr_n) { color = clr_n; }

void Symbol::set_background(const Effect & bg_n) { background = bg_n; }


#endif /* symbol_hpp */
