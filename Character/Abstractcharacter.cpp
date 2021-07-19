#include "Abstractcharacter.h"
#include <QDebug>

AbstractCharacter::AbstractCharacter() : mXPos(0), mYPos(0), mHp(0), mAtt(0), mDef(0), mAgil(0) {}

bool AbstractCharacter::move(int64_t x, int64_t y) {
    if (mMoveAllowment == true) {
        this->mXPos += x;
        this->mYPos += y;
    }

    return true;
}

bool AbstractCharacter::attck(AbstractCharacter* target) {
    int64_t atDef = this->mAtt - target->getDef();
    int64_t tarHp = target->getHp();

    bool ret = true;
    if (atDef > 0) {
        tarHp -= atDef;
    } else {
    }
    target->setHP(tarHp);

    return ret;
}

void AbstractCharacter::setHP(int64_t hp) {
    mHp = hp;
}

int64_t AbstractCharacter::getDef() {
    return mDef;
}

int64_t AbstractCharacter::getAgil() {
    return mAgil;
}

int64_t AbstractCharacter::getHp() {
    return mHp;
}

int64_t AbstractCharacter::getAtt() {
    return mAtt;
}
