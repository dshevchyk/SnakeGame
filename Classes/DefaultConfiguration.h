//
//  Configuration.h
//  ExpJam
//
//  Created by dmytros on 3/18/18.
//

#ifndef Configuration_h
#define Configuration_h

#include "cocos2d.h"
//for now static configuration, for future xml configuration will be preferable
struct DefaultConfiguration
{
    static cocos2d::Size frameSize;
    static cocos2d::Size snakeDefaultSize;
    static float speed;
    static float minMovement;
    static size_t snakeMaxSize;
};

#endif /* Configuration_h */
