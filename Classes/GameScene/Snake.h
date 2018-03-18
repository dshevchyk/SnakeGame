//
//  Snake.h
//  ExpJam
//
//  Created by dmytros on 18/03/2018.
//
//

#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "cocos2d.h"
#include "MoveDirection.h"
#include "DefaultConfiguration.h"
class SnakeHead;
class Snake : public cocos2d::Node
{
public:
    CREATE_FUNC(Snake);
    
    void setDirection(MoveDirection);
    MoveDirection getDirection();
    
protected:
    bool init() override;
    void onEnter() override;
    
    void onExit() override;
    //  update the snake states
    void update(float dt) override;

private:
    //  the snake moving direction
    MoveDirection m_currentDirection = MoveDirection::Right;
    //  the head of snake
    SnakeHead* m_head = nullptr;
    float m_currentSpeed = DefaultConfiguration::speed;;
    float m_bufferMovement = 0.f;
};


#endif // __SNAKE_H__

