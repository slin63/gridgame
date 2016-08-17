#ifndef TREE_HPP
#define TREE_HPP

#include "coordinates.hpp"
#include "gameobject.hpp"

class Tree : public GameObject {
public:
    Tree()
    {
        set_symbol(s_symbol), set_health(s_health), set_color(s_color);
    }
    Tree(const CRDS&);

private:
    char s_symbol = 'Y';
    int s_health = 20;
    std::string s_color = "\033[0;32m"; // ANSI-Green
};

#endif
