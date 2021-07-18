#ifndef HUMAN_H
#define HUMAN_H

#include <Abstractcharacter.h>

class Human : public AbstractCharacter {
public:
    explicit Human();
    explicit Human(int64_t hp, int64_t att, int64_t def, int64_t agil);
};

#endif  // HUMAN_H
