//
//  BaseCell.h
//  ExpJam
//
//  Created by dmytros on 18/03/2018.
//
//

#ifndef __BaseCell_H__
#define __BaseCell_H__

#include "cocos2d.h"

class BaseCell: public cocos2d::Node
{
public:
    cocos2d::Rect getRect();
    virtual const char* getSpriteName() const = 0;
protected:
    bool init() override;
protected:
    cocos2d::Sprite* m_Sprite = nullptr;
};
#endif // __BaseCell_H__

