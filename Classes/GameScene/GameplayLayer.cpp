//
//  GameplayLayer.cpp
//  ExpJam
//
//  Created by dmytros on 18/03/2018.
//
//

#include "GameplayLayer.h"
#include "Snake.h"
#include "Food.h"
USING_NS_CC;

// on "init" you need to initialize your instance
bool GameplayLayer::init()
{
    // super init first
    if ( !Layer::init() )
    {
        return false;
    }
    m_snake = Snake::create();
    this->addChild(m_snake);
    
    addFood();
    return true;
}

void GameplayLayer::onEnter()
{
    Layer::onEnter();
    // schedule update calls
    scheduleUpdate();
}

void GameplayLayer::onExit()
{
    Layer::onExit();
    // unschedule update
    unscheduleUpdate();
}

void GameplayLayer::update( float delta )
{
    m_snake->move(delta * m_currentSpeed);
    if(m_food && m_snake->getHeadRect().intersectsRect(m_food->getRect()))
    {
        addFood();
        m_snake->growUp();
    }
    // called once per frame
//    log( "Update: %f", delta );
    
}
void GameplayLayer::addFood()
{
    if (m_food != NULL)
        this->removeChild(m_food, true);
    
    Size winSize = DefaultConfiguration::frameSize;
    auto x = rand() % (int)winSize.width;
    auto y =  winSize.height  /2;//rand() % (int)winSize.height;
    m_food = Food::create();
    m_food->setPosition(Vec2(x, y));
    this->addChild(m_food);
}



