#include "Snake.h"
#include "SnakeHead.h"
#include "BodyCell.h"
#include "DefaultConfiguration.h"
USING_NS_CC;



bool Snake::move(float dMove)
{
    //  update the position for next movement
    m_bufferMovement += dMove;
    if(m_bufferMovement >= DefaultConfiguration::minMovement)
    {
        for(auto i =  m_body.size() - 1; i > 0; --i)
        {
            m_body[i]->setPosition(m_body[i-1]->getPosition());
        }
        m_head->move(DefaultConfiguration::minMovement);
        m_bufferMovement = 0.f;
        return true;
    }
    return false;
}

bool Snake::init() {
    // super init first
    if ( !Node::init() )
    {
        return false;
    }
    //    // setup the head
    m_body.reserve(DefaultConfiguration::snakeMaxSize);
    m_head = SnakeHead::create();
    m_head->setDirection(m_currentDirection);
    this->addChild(m_head);
    m_body.push_back(m_head);
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
    if (m_body.size() < DefaultConfiguration::snakeMaxSize ) {
        //  get snake head position and direction
        Point point = m_head->getPosition();
        
        //  create a snake body
        BaseCell* bodyItem = BodyCell::create();
        //  set body item to head position
        bodyItem->setPosition(point);
        this->addChild(bodyItem);
        m_body.push_back(bodyItem);
        if(m_body.size() > 1)
        {
            for (auto i = m_body.size() - 2; i > 0; --i)
            {
                std::iter_swap(m_body.begin() +i, m_body.begin() +i+1);
            }
        }
        
        m_body[1] = bodyItem;
        
        m_head->move(m_head->getRect().size.width);
    }
}
Rect Snake::getHeadRect()
{
    return m_head->getRect();
}

void Snake::setHeadPosition(const cocos2d::Vec2& headPos)
{
    m_head->setPosition(headPos);
}
