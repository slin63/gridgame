#ifndef TREE_HPP
#define TREE_HPP

#include "staticobject.hpp"

class Tree : public StaticObject {
public:
    Tree();
    Tree(const CRDS&);

private:
    char static_symbol = 'Y';
    int static_health = 20;
    int static_draw_priority = 3;
    Symbol::Effect static_color = Symbol::GREEN; // ANSI-Green
};

#endif
