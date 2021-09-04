#ifndef HUMAN_H
#define HUMAN_H

#include <Abstractcharacter.h>

class Human : public AbstractCharacter {
public:
    explicit Human(int64_t hp = 100, int64_t att = 20, int64_t def = 10, int64_t agil = 30);
};

#endif  // HUMAN_H
