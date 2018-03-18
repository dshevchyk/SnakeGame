//
//  Food.h
//  ExpJam
//
//  Created by dmytros on 18/03/2018.
//
//

#ifndef __FOOD_H__
#define __FOOD_H__

#include "cocos2d.h"
#include "BaseCell.h"

class Food: public BaseCell
{
public:
    CREATE_FUNC(Food);
    const char* getSpriteName() const override;
    
};
#endif // __SNAKE_HEAD_H__
