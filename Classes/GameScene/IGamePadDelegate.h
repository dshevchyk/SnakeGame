//
//  IGamePadDelegate.h
//  ExpJam
//
//  Created by dmytros on 3/19/18.
//

#ifndef IGamePadDelegate_h
#define IGamePadDelegate_h

#include "cocos2d.h"
enum class MoveDirection;
class IGamePadDelegate
{
public:
    virtual void onGamePadClicked(MoveDirection direction){}
    
};

#endif /* IGamePadDelegate_h */
