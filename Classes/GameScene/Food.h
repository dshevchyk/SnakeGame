//
//  Food.h
//  ExpJam
//
//  Created by dmytros on 18/03/2018.
//
//

#ifndef __FOOD_H__
#define __FOOD_H__

#include "cocos2d.h"


class Food: public cocos2d::Node
{
public:
    CREATE_FUNC(Food);
    cocos2d::Rect getRect();
protected:
    bool init() override;
private:
    cocos2d::Sprite *m_foodSprite = nullptr;    // the player of the snake
};
#endif // __SNAKE_HEAD_H__
