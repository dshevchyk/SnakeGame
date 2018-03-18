//
//  SnakeHead.h
//  ExpJam
//
//  Created by dmytros on 18/03/2018.
//
//

#ifndef __SNAKE_HEAD_H__
#define __SNAKE_HEAD_H__

#include "BaseCell.h"

#include "MoveDirection.h"
class SnakeHead : public BaseCell
{
public:
    CREATE_FUNC(SnakeHead);
    const char* getSpriteName() const override;
    // set the direction for next movement
    void setDirection(MoveDirection);
    // get the current diraction
    MoveDirection getDirection();
    // move head by value
    void move(float value);
protected:
    
    // scene initialisation
    bool init() override;
    
    cocos2d::Point getAdjustedPosition(cocos2d::Point newPosition);

    void setRotation(MoveDirection currentDirection);
protected:
    
    //direction for next movements
    MoveDirection m_currentDirection = MoveDirection::Right;
};

#endif // __SNAKE_HEAD_H__
