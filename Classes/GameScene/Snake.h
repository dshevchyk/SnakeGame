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
class SnakeHead;
class BaseCell;
class Snake : public cocos2d::Node
{
public:
    CREATE_FUNC(Snake);
    
    void setDirection(MoveDirection);
    MoveDirection getDirection();
    
    void move(float dMove);
    void growUp();
    cocos2d::Rect getHeadRect();
protected:
    bool init() override;
    void onEnter() override;
    
    void onExit() override;
    //  update the snake states

private:
    //  the snake moving direction
    MoveDirection m_currentDirection = MoveDirection::Right;
    //  the head of snake
    SnakeHead* m_head = nullptr;
    std::vector<BaseCell*> m_body;
    float m_bufferMovement = 0.f;
};


#endif // __SNAKE_H__

