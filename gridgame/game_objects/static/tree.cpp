#include "tree.hpp"

Tree::Tree() {
    health = static_health;
    symbol->set_symbol(static_symbol);
    symbol->set_color(static_color);
    draw_priority = static_draw_priority;
    dead_color = Symbol::Effect::WHITE;
    dead_symbol = 'x';
    name = "Tree";
}

Tree::Tree(const CRDS& coords) {
    symbol->set_symbol(static_symbol);
    symbol->set_color(static_color);
    health = static_health;
    draw_priority = static_draw_priority;
    name = "Tree";
    dead_color = Symbol::Effect::WHITE;
    dead_symbol = 'x';
    c = coords;
}
