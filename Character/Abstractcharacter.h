#ifndef ABSTRACTCHARACTER_H
#define ABSTRACTCHARACTER_H

#include <memory>

class AbstractCharacter {
public:
    explicit AbstractCharacter();
    virtual ~AbstractCharacter(){};

    virtual bool move(int64_t x, int64_t y);
    virtual bool attck(AbstractCharacter* target);

public:
    void setHP(int64_t hp);

    int64_t getDef();
    int64_t getAgil();
    int64_t getHp();
    int64_t getAtt();

protected:
    void attacked();

protected:
    int64_t mXPos;
    int64_t mYPos;
    int64_t mHp;
    int64_t mAtt;
    int64_t mDef;
    int64_t mAgil;

private:
    bool mMoveAllowment = true;
};

#endif  // ABSTRACTCHARACTER_H
