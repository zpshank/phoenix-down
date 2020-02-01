#ifndef _CREATURE_H_
#define _CREATURE_H_
#include <Sprite.h>
#include <SDL_render.h>

namespace pp = powderpuff;

class Creature
{
public:
    Creature(int attack_power, int init_health, pp::Sprite* sprite = nullptr);
    void attack(Creature& creature);
    bool isDead();
    virtual void receiveAttack(Creature* creature);
    virtual int attackPower();

private:
    pp::Sprite* sprite;
    int init_health;
    int health;
    int attack_power;
};
#endif