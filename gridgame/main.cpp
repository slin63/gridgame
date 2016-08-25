// Conceptually like dwarf fortress adventure mode . . .
// Main goals:
//  Implement objects effectively and maintanably (sic)
//  Render objects
//  Darkness effect (objects out of certain radius are dimmed and color-shifted)
// http://stackoverflow.com/questions/22146094/why-should-i-use-a-pointer-rather-than-the-object-itself
//      - http://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
// http://www.cplusplus.com/forum/articles/12974/
// http://www.cplusplus.com/doc/tutorial/inheritance/
// http://www.cplusplus.com/forum/general/107753/

#include <iostream>
#include "renderer.hpp"
#include "manager.hpp"
#include "player.hpp"
#include "symbol.hpp"

// Idea: Have it be a "1 - dimensional" dungeon crawler: The map is (5 * 100) wide and you just keep moving forward beating things up until you die


int main(int argc, const char * argv[]) {
    srand(time(NULL));

    std::cout << "This gonna dim:";
    Symbol s('!', Symbol::CYAN, Symbol::DEFAULT, Symbol::RED_BG);
//    s.set_symbol('s');
//    s.set_color(Symbol::CYAN);
//    s.set_background(Symbol::RED_BG);
//    s.set_effect(Symbol::DIM);
    s.draw_symbol();
    s.draw_dark();
    std::cout << " We Good? :" << std::endl;
    
//    Manager g(5, 5);
//    
//    RenderBox r_box(g);
//    r_box.list_elements();//    g.step();
//    r_box.list_elements();
}
