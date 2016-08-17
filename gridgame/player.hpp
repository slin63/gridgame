#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "gameobject.hpp"

class Player {
public:
    Player() = default;
    Player(const GameObject&);

private:
    GameObject avatar;
};

#endif
