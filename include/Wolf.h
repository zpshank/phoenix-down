#ifndef _WOLF_H_
#define _WOLF_H_
#include <Creature.h>

class Wolf : public Creature
{
public:
    Wolf(pp::Sprite* sprite == nullptr)
        :Creature(3, 1, sprite)
    {};
};

#endif