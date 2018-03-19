//
//  GamePadLayer.cpp
//  ExpJam
//
//  Created by dmytros on 18/03/2018.
//
//

#include "GamePadLayer.h"
#include "Snake.h"
#include "Food.h"
#include "IGamePadDelegate.h"
USING_NS_CC;

// on "init" you need to initialize your instance
bool GamePadLayer::init()
{
    // super init first
    if ( !Layer::init() )
    {
        return false;
    }

    
    Size visibleSize = Director::getInstance()->getVisibleSize();

    auto button = addControlBotton(MoveDirection::Left);
    button->setPosition(Vec2((DefaultConfiguration::gamePadButtonSize.height - visibleSize.width)/ 2, 0) );
    button = addControlBotton(MoveDirection::Right);
    button->setPosition(Vec2((-DefaultConfiguration::gamePadButtonSize.height + visibleSize.width)/ 2, 0) );
    button = addControlBotton(MoveDirection::Up);
    button->setPosition(Vec2(0, (-DefaultConfiguration::gamePadButtonSize.height + visibleSize.height)/ 2) );
    button = addControlBotton(MoveDirection::Down);
    button->setPosition(Vec2(0, (DefaultConfiguration::gamePadButtonSize.height - visibleSize.height)/ 2) );
    return true;
}

ui::Button* GamePadLayer::addControlBotton(MoveDirection direction)
{
    auto button = ui::Button::create("button.png", "buttonSelected.png");
    button->setContentSize(DefaultConfiguration::gamePadButtonSize);
    button->setRotation(static_cast<int>(direction));
    button->setOpacity(DefaultConfiguration::gamePadOpacity);
    this->addChild(button);
    button->addTouchEventListener([this, direction](Ref* sender, ui::Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::ENDED:
                if(m_delegate) {
                    m_delegate->onGamePadClicked(direction);
                }
                break;
            default:
                break;
        }
    });
    return button;
}
void GamePadLayer::onEnter()
{
    Layer::onEnter();
    // schedule update calls
    //scheduleUpdate();
}

void GamePadLayer::onExit()
{
    Layer::onExit();
    // unschedule update
    //unscheduleUpdate();
}


void GamePadLayer::setDelegate(IGamePadDelegate* delegate)
{
    m_delegate = delegate;
}
const IGamePadDelegate* GamePadLayer::getDelegate() const
{
    return m_delegate;
}


