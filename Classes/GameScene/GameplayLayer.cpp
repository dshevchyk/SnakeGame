//
//  GameplayLayer.cpp
//  ExpJam
//
//  Created by dmytros on 18/03/2018.
//
//

#include "GameplayLayer.h"
#include "Snake.h"
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
    
    return true;
}

void GameplayLayer::onEnter()
{
    Layer::onEnter();
    // schedule update calls
//    scheduleUpdate();
}

void GameplayLayer::onExit()
{
    Layer::onExit();
    // unschedule update
//    unscheduleUpdate();
}

void GameplayLayer::update( float delta )
{
    // called once per frame
//    log( "Update: %f", delta );
    
}



