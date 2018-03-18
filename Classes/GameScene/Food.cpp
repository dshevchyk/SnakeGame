//
//  Food.cpp
//  ExpJam
//
//  Created by dmytros on 18/03/2018.
//
//

#include "Food.h"
#include "DefaultConfiguration.h"

USING_NS_CC;

bool Food::init() {
    if ( !Node::init() )
    {
        return false;
    }
    m_foodSprite = Sprite::create("head.png");
    m_foodSprite->setScale(DefaultConfiguration::snakeDefaultSize.width  / m_foodSprite->getContentSize().width,
                 DefaultConfiguration::snakeDefaultSize.height  / m_foodSprite->getContentSize().height);

    this->addChild(m_foodSprite);
    return true;
}

Rect Food::getRect()
{
    auto bodySize = m_foodSprite->getContentSize() * m_foodSprite->getScale();
    return Rect(getPosition().x - bodySize.width / 2,
                getPosition().y - bodySize.height / 2,
                bodySize.width,
                bodySize.height);
}


