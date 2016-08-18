#include "tree.hpp"

Tree::Tree(const CRDS& coords) {
    set_symbol(s_symbol);
    set_health(s_health);
    set_color(s_color);
    c = coords;
}
