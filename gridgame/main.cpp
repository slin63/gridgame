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
#include "coordinates.hpp"
#include "human.hpp"
#include "tree.hpp"
#include "renderer.hpp"
#include "manager.hpp"
#include "player.hpp"


int main(int argc, const char * argv[]) {
    srand(time(NULL));
    Human a(CRDS(2, 3));
    Human b(CRDS(4, 5));
    Human c(CRDS(4, 3));
    a.rand_walk();
    Tree d(CRDS(6,6));
    Player player(a);

    Manager g;
    g.add(a);
    g.add(d);

    RenderBox r_box(g);
    r_box.render_grid();
}
