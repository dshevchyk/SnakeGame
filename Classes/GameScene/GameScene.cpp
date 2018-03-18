//
//  GameScene.cpp
//  ExpJam
//
//  Created by dmytros on 18/03/2018.
//
//

#include "GameScene.h"
USING_NS_CC;

// on "init" you need to initialize your instance
bool GameScene::init()
{
    // super init first
    if ( !Scene::init() )
    {
        return false;
    }
    return true;
}

void GameScene::onEnter()
{
    Scene::onEnter();
    // schedule update calls
    scheduleUpdate();
}

void GameScene::onExit()
{
    Scene::onExit();
    // unschedule update
    unscheduleUpdate();
}

void GameScene::update( float delta )
{
    // called once per frame
//    cocos2d::log( "Update: %f", delta );
    
}



