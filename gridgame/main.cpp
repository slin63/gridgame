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
#include <unistd.h>
#include "constants.hpp"
#include "renderer.hpp"
#include "manager.hpp"
#include "player.hpp"
#include "symbol.hpp"

// Idea: Have it be a "1 - dimensional" dungeon crawler: The map is (5 * 100) wide and you just keep moving forward beating things up until you die


int main(int argc, const char * argv[]) {
    srand(time(NULL));
    
    Manager g(GLOBAL_X, GLOBAL_Y);
    
    RenderBox r_box(g);
    GameObject* plyr = g.get_player()->get_avatar();
    plyr->set_coord(CRDS(20,0));
    size_t move;
    // Enum for movement keys
    std::cout << r_box.draw_view_of(plyr) << std::endl;
    while(std::cin >> move)
    {
        switch (move) {
            case 0:
                plyr->up();
                break;
            case 1:
                plyr->down();
                break;
            case 2:
                plyr->left();
                break;
            case 3:
                plyr->right();
                break;
            case 4:
                plyr->wait();
                break;
            
            default:
                break;
        }
        std::cout << r_box.draw_view_of(plyr) << std::endl;
        g.step();
        sleep(0.5);
    }
//    std::cout << '1' << std::endl;
}
