#ifndef _CREATURE_H_
#define _CREATURE_H_
#include <Sprite.h>
#include <SDL_render.h>

namespace pp = powderpuff;

class Creature
{
public:
    Creature(int attack_power, int init_health, pp::Sprite* sprite_ = nullptr);
    void attack(Creature& creature);
    bool isDead();
    virtual void receiveAttack(Creature* creature);
    virtual int attackPower();
    virtual int health();
    virtual int initHealth();
    void setSprite(pp::Sprite* sprite_);
    pp::Sprite* sprite();
    void reset();

private:
    pp::Sprite* sprite_;
    int init_health;
    int health_;
    int attack_power;
};
#endif