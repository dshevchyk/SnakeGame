//
//  SnakeHead.cpp
//  ExpJam
//
//  Created by dmytros on 18/03/2018.
//
//

#include "SnakeHead.h"
#include "DefaultConfiguration.h"
USING_NS_CC;

const char* SnakeHead::getSpriteName() const
{
    return "head.png";
}
bool SnakeHead::init() {
    if ( !BaseCell::init() )
    {
        return false;
    }
    setRotation(m_currentDirection);
    return true;
}

void SnakeHead::setDirection(MoveDirection newDirection)
{
    if (newDirection != m_currentDirection && MoveDirectionHelpder::GetOppositeDirection(m_currentDirection) != newDirection)
    {
        m_currentDirection = newDirection;
        // change the avatar face to the corresponding rotation
        setRotation(m_currentDirection);
    }
}
void SnakeHead::setRotation(MoveDirection currentDirection)
{
    m_Sprite->setRotation(static_cast<int>(currentDirection));
}
MoveDirection SnakeHead::getDirection()
{
    return m_currentDirection;
}

void SnakeHead::move(float moveUnit)
{
    // set new position
    Point newPosition = getPosition();
    switch(m_currentDirection)
    {
        case MoveDirection::Up:
            newPosition.y += moveUnit;
            break;
        case MoveDirection::Down:
            newPosition.y -= moveUnit;
            break;
        case MoveDirection::Right:
            newPosition.x += moveUnit;
            break;
        case MoveDirection::Left:
            newPosition.x -= moveUnit;
        default:
            break;
    }
    setPosition(getAdjustedPosition(newPosition));
}

Point SnakeHead::getAdjustedPosition(Point newPosition)
{
    float objectWidth = getContentSize().width;
    float objectHeight = getContentSize().height;
    
    float halfObjectWidth = objectWidth / 2;
    float halfObjectHeight = objectHeight / 2;
    
    // adjust newPosition to legal
    Size winSize = Director::getInstance()->getWinSize();
    float top = winSize.height - halfObjectHeight;
    float floor = 0 + halfObjectHeight;
    float right = winSize.width - halfObjectWidth;
    float left = 0  + halfObjectWidth;
    
    //  check newPosition and give new value
    if (newPosition.y > top + halfObjectHeight)
        newPosition.setPoint(newPosition.x, floor);
    
    else if (newPosition.y < floor - halfObjectHeight)
        newPosition.setPoint(newPosition.x, top);
    
    else if (newPosition.x > right + halfObjectWidth)
        newPosition.setPoint(left, newPosition.y);
    
    else if (newPosition.x < left - halfObjectWidth)
        newPosition.setPoint(right, newPosition.y);
    
    return newPosition;
}


