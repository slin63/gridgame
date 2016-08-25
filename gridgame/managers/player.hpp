#ifndef PLAYER_HPP
#define PLAYER_HPP

class GameObject;

class Player {
public:
    Player() = default;
    Player(GameObject*);
    inline void set_avatar(GameObject*);
    inline GameObject* get_avatar(void);

private:
    GameObject* avatar;
};

void Player::set_avatar(GameObject* g_obj) { avatar = g_obj; }

GameObject* Player::get_avatar(void) { return avatar; }

#endif
