#ifndef _GHOST_H_
#define _GHOST_H_
#include <Creature.h>

class Ghost : public Creature
{
public:
    Ghost(pp::Sprite* sprite = nullptr)
        :Creature(1, 3, sprite)
    {};
};

#endif