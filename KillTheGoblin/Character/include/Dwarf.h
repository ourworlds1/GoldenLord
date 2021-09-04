#ifndef DWARF_H
#define DWARF_H

#include <Abstractcharacter.h>

class Dwarf : public AbstractCharacter {
public:
    explicit Dwarf(int64_t hp = 200, int64_t att = 15, int64_t def = 20, int64_t agil = 20);
};

#endif  // DWARF_H
