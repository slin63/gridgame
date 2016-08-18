#include "tree.hpp"

Tree::Tree() {
    symbol = static_symbol;
    health = static_health;
    color = static_color;
    draw_priority = static_draw_priority;
}

Tree::Tree(const CRDS& coords) {
    symbol = static_symbol;
    health = static_health;
    color = static_color;
    draw_priority = static_draw_priority;
    c = coords;
}