//
//  IMenuDelegate.h
//  ExpJam
//
//  Created by dmytros on 18/03/2018.
//
//

#ifndef __IMENU_DELEGATE_H__
#define __IMENU_DELEGATE_H__

#include "cocos2d.h"

class IMenuDelegate
{
public:
    virtual void onStartClicked(){}
    virtual void onMultiplayerClicked(){};
    virtual void onSettingsClicked(){}
    virtual void onHelpClicked(){}
    virtual void onExitClicked(){}
    
};

#endif //__IMENU_DELEGATE_H__
