#ifndef _SKELETON_H_
#define _SKELETON_H_
#include <Creature.h>

class Skeleton : public Creature
{
public:
    Skeleton(pp::Sprite* sprite == nullptr)
        :Creature(2, 2, sprite)
    {};
};
#endif
