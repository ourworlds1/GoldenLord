#ifndef ORC_H
#define ORC_H

#include <Abstractcharacter.h>

class Orc : public AbstractCharacter {
public:
    explicit Orc(int64_t hp = 150, int64_t att = 30, int64_t def = 10, int64_t agil = 15);
};

#endif  // ORC_H
