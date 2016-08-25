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
    std::string static_color = "\033[0;32m"; // ANSI-Green
};

#endif
