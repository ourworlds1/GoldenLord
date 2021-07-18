#include "Human.h"

Human::Human() {
    mXPos = 0;
    mYPos = 0;
}

Human::Human(int64_t hp, int64_t att, int64_t def, int64_t agil) {
    mHp = hp;
    mAtt = att;
    mDef = def;
    mAgil = agil;
}
