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
#include "Player.h"
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
    
    m_snake->setHeadPosition(Vec2(std::rand() % (int)DefaultConfiguration::frameSize.width,
                              std::rand() % (int)DefaultConfiguration::frameSize.height));
    this->addChild(m_snake);
    
    m_anotherSnake = Snake::create();
    m_anotherSnake->setHeadPosition(Vec2(std::rand() % (int)DefaultConfiguration::frameSize.width,
                                     std::rand() % (int)DefaultConfiguration::frameSize.height));
    this->addChild(m_anotherSnake);
    m_player = std::unique_ptr<Player>(new Player(m_anotherSnake));
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
    if( m_snake->getHeadRect().intersectsRect(m_food->getRect()))
    {
        addFood();
        m_snake->growUp();
    }
    if ( m_anotherSnake->getHeadRect().intersectsRect(m_food->getRect()))
    {
        addFood();
        m_anotherSnake->growUp();
    }
    m_snake->move(delta * m_currentSpeed);
    if(m_anotherSnake->move(delta * m_currentSpeed))
    {
        m_player->play(m_food->getPosition());
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
    auto y =  rand() % (int)winSize.height;
    m_food = Food::create();
    m_food->setPosition(Vec2(x, y));
    this->addChild(m_food);
}

void GameplayLayer::setDirection(MoveDirection direction)
{
    m_snake->setDirection(direction);
}



