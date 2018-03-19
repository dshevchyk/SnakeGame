//
//  Player.cpp
//  ExpJam
//
//  Created by dmytros on 3/19/18.
//

#include "Player.h"
#include "Snake.h"
#include "MoveDirection.h"
#include "DefaultConfiguration.h"

Player::Player(Snake* snake)
{
    m_mySnake = snake;
}

MoveDirection Player::searchDirection(cocos2d::Point destination)
{
    auto headPosition = m_mySnake->getHeadRect().origin;
    MoveDirection currentDirection = m_mySnake->getDirection();
    
    
    //  get the distance
    float x = destination.x - headPosition.x;
    float y = destination.y - headPosition.y;

    float absX = abs(x);
    float absY = abs(y);

    //0.5 * DefaultConfiguration::minMovement + 1 - to make snake movements more smart
    if ((currentDirection == MoveDirection::Up || currentDirection == MoveDirection::Down) && absX > 0.5 * DefaultConfiguration::minMovement + 1)
    {
        if (x > 0)
            return MoveDirection::Right;
        else if (x < 0)
            return MoveDirection::Left;
        else {}
    }
    else if ((currentDirection == MoveDirection::Right || currentDirection == MoveDirection::Left)&& absY >0.5 * DefaultConfiguration::minMovement + 1)
    {
        if (y > 0)
            return MoveDirection::Up;
        else if (y < 0)
            return MoveDirection::Down;
        else {}
    }
    return currentDirection;
}


void Player::play(cocos2d::Point destination)
{
    m_mySnake->setDirection(searchDirection(destination));
}

