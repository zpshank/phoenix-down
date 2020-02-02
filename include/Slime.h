#ifndef _SLIME_H_
#define _SLIME_H_
#include <Creature.h>

class Slime : public Creature
{
public:
    Slime(pp::Sprite* sprite = nullptr)
        :Creature(1, 1, sprite)
    {};
};
#endif