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
#include "interactions.hpp"
#include "symbol.hpp"
#include "gamemgr.hpp"


// Idea: Have it be a "1 - dimensional" dungeon crawler: The map is (5 * 100) wide and you just keep moving forward beating things up until you die

// Nearby obj function still borked


int main(int argc, const char * argv[]) {
    srand(time(NULL));

    GameMgr game;
    
    game.action_menu();
}
