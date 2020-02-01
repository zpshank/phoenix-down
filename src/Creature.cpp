#include <Creature.h>

Creature::Creature(int attack_power, int init_health, pp::Sprite* sprite)
    :attack_power(attack_power)
    , init_health(init_health)
    , health(init_health)
    , sprite(sprite)
{
}

int Creature::attackPower()
{
    return attack_power;
}

void Creature::attack(Creature& creature)
{
    creature.receiveAttack(this);
}

void Creature::receiveAttack(Creature* creature)
{
    health -= creature->attackPower();
}

bool Creature::isDead()
{
    return health == 0;
}