#ifndef ELF_H
#define ELF_H

#include <Abstractcharacter.h>

class Elf : public AbstractCharacter {
public:
    explicit Elf(int64_t hp = 80, int64_t att = 20, int64_t def = 10, int64_t agil = 40);
};

#endif  // ELF_H
