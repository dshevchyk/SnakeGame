//
//  MenuLayer.h
//  ExpJam
//
//  Created by dmytros on 18/03/2018.
//
//

#ifndef __MENU_LAYER_H__
#define __MENU_LAYER_H__

#include "cocos2d.h"

class IMenuDelegate;

class MenuLayer : public cocos2d::Layer
{
public:
    CREATE_FUNC(MenuLayer);
    //munu listener getter/setter
    void setDelegate(IMenuDelegate* delegate);
    const IMenuDelegate* getDelegate() const;
protected:
    // layer initialisation
    bool init() override;
    // scene shown
    void onEnter() override;
    // scene hidden
    void onExit() override;
    
    //menu listener
    IMenuDelegate* m_Delegate = nullptr;
};

#endif //__MENU_LAYER_H__
