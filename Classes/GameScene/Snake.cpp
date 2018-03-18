#include "Snake.h"
#include "SnakeHead.h"
#include "DefaultConfiguration.h"
USING_NS_CC;



void Snake::move(float dMove)
{
    //  update the position for next movement
    m_bufferMovement += dMove;
    if(m_bufferMovement > DefaultConfiguration::minMovement)
    {
        m_head->move(m_bufferMovement);
        m_bufferMovement = 0.f;
    }
}

bool Snake::init() {
    // super init first
    if ( !Node::init() )
    {
        return false;
    }
    //    // setup the head
    m_head = SnakeHead::create();
    m_head->setDirection(m_currentDirection);
    m_head->setPosition(Vec2(100, DefaultConfiguration::frameSize.height / 2));
    this->addChild(m_head);
    
    //TODO setup body
    return true;
}

void Snake::onEnter()
{
    Node::onEnter();
    // schedule update calls
    scheduleUpdate();
}

void Snake::onExit()
{
    Node::onExit();
    // unschedule update
    unscheduleUpdate();
}
MoveDirection Snake::getDirection()
{
    return m_currentDirection;
}

void Snake::setDirection(MoveDirection newDirection)
{
    if (newDirection != m_currentDirection && MoveDirectionHelpder::GetOppositeDirection(m_currentDirection) != newDirection)
    {
        m_bufferMovement = 0.f;
        m_currentDirection = newDirection;
        m_head->setDirection(m_currentDirection);
    }
}

void Snake::growUp()
{
    //TODO
}
Rect Snake::getHeadRect()
{
    auto headSize = m_head->getBodySize();
    return Rect(m_head->getPosition().x - headSize.width / 2,
                m_head->getPosition().y - headSize.height / 2,
                headSize.width,
                headSize.height);
}