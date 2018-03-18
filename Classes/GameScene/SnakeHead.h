//
//  SnakeHead.h
//  ExpJam
//
//  Created by dmytros on 18/03/2018.
//
//

#ifndef __SNAKE_HEAD_H__
#define __SNAKE_HEAD_H__

#include "cocos2d.h"

#include "MoveDirection.h"
class SnakeHead : public cocos2d::Node
{
public:
    CREATE_FUNC(SnakeHead);
    // set the direction for next movement
    void setDirection(MoveDirection);
    // get the current diraction
    MoveDirection getDirection();
    // move head by value
    void move(float value);
    cocos2d::Size getBodySize() const;
protected:
    
    // scene initialisation
    bool init() override;
    
    cocos2d::Point getAdjustedPosition(cocos2d::Point newPosition);

    void setRotation(MoveDirection currentDirection);
protected:
    
    //direction for next movements
    MoveDirection m_currentDirection = MoveDirection::Right;
    cocos2d::Sprite* m_headSprite = nullptr;
};

#endif // __SNAKE_HEAD_H__
