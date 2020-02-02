#include <Creature.h>

Creature::Creature(int attack_power, int init_health, pp::Sprite* sprite_)
    :attack_power(attack_power)
    , init_health(init_health)
    , health_(init_health)
    , sprite_(sprite_)
{
}

int Creature::attackPower()
{
    return attack_power;
}

int Creature::health()
{
    return health_;
}

int Creature::initHealth()
{
    return init_health;
}

void Creature::attack(Creature& creature)
{
    creature.receiveAttack(this);
}

void Creature::receiveAttack(Creature* creature)
{
    health_ -= creature->attackPower();
}

bool Creature::isDead()
{
    return health_ <= 0;
}

void Creature::setSprite(pp::Sprite* sprite_)
{
    this->sprite_ = sprite_;
}

pp::Sprite* Creature::sprite()
{
    return sprite_;
}

void Creature::reset()
{
    health_ = init_health;
}