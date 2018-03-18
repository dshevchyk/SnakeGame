//
//  GameScene.cpp
//  ExpJam
//
//  Created by dmytros on 18/03/2018.
//
//

#include "GameScene.h"
#include "GameplayLayer.h"
USING_NS_CC;

// on "init" you need to initialize your instance
bool GameScene::init()
{
    // super init first
    if ( !Scene::init() )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    Sprite *bg = Sprite::create("GameplayBG.png");
    bg->setScale(visibleSize.width / bg->getContentSize().width,
                 visibleSize.height / bg->getContentSize().height);
    bg->setPosition(Point(origin.x + visibleSize.width/2,
                          origin.y + visibleSize.height/2));
    this->addChild(bg);
    
    
    m_GameplayLayer = GameplayLayer::create();
    this->addChild(m_GameplayLayer);
    
    return true;
}

void GameScene::onEnter()
{
    Scene::onEnter();
    // schedule update calls
//    scheduleUpdate();
}

void GameScene::onExit()
{
    Scene::onExit();
    // unschedule update
//    unscheduleUpdate();
}

void GameScene::update( float delta )
{
    // called once per frame
    //log( "Update: %f", delta );
    
}



