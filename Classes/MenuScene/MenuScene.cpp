//
//  MenuScene.cpp
//  ExpJam
//
//  Created by dmytros on 18/03/2018.
//
//

#include "MenuScene.h"
#include "MenuLayer.h"
#include "GameScene.h"
USING_NS_CC;



// on "init" you need to initialize your instance
bool MenuScene::init()
{
    // super init first
    if ( !Scene::init() )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    Sprite *bg = Sprite::create("SnakeMenuBg.png");
    bg->setScale(visibleSize.width / bg->getContentSize().width,
                 visibleSize.height / bg->getContentSize().height);
    bg->setPosition(Point(origin.x + visibleSize.width/2,
                          origin.y + visibleSize.height/2));
    this->addChild(bg);

    m_menuLayer = MenuLayer::create();
    m_menuLayer->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 50));
    this->addChild(m_menuLayer);
    
    return true;
}

void MenuScene::onEnter()
{
    Scene::onEnter();
    m_menuLayer->setDelegate(this);
    // schedule update calls
    scheduleUpdate();
}

void MenuScene::onExit()
{
    Scene::onExit();
    m_menuLayer->setDelegate(nullptr);
    // unschedule update
    unscheduleUpdate();
}

void MenuScene::update( float delta )
{
    // called once per frame
//    cocos2d::log( "Update: %f", delta );
    
}


void MenuScene::onStartClicked()
{
    cocos2d::log( "MenuScene::onStartClicked");
    Director::getInstance()->pushScene(GameScene::create());
}

void MenuScene::onExitClicked()
{
    cocos2d::log( "MenuScene::onExitClicked");
    Director::getInstance()->end();
}

