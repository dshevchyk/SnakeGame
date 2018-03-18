//
//  BaseCell.cpp
//  ExpJam
//
//  Created by dmytros on 18/03/2018.
//
//

#include "BaseCell.h"
#include "DefaultConfiguration.h"

USING_NS_CC;

bool BaseCell::init() {
    if ( !Node::init() )
    {
        return false;
    }
    m_Sprite = Sprite::create(getSpriteName());
    m_Sprite->setScale(DefaultConfiguration::snakeDefaultSize.width  / m_Sprite->getContentSize().width,
                 DefaultConfiguration::snakeDefaultSize.height  / m_Sprite->getContentSize().height);

    this->addChild(m_Sprite);
    return true;
}

Rect BaseCell::getRect()
{
    auto bodySize = m_Sprite->getContentSize() * m_Sprite->getScale();
    return Rect(getPosition().x - bodySize.width / 2,
                getPosition().y - bodySize.height / 2,
                bodySize.width,
                bodySize.height);
}


