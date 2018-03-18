//
//  MenuScene.h
//  ExpJam
//
//  Created by dmytros on 18/03/2018.
//
//

#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"
#include "IMenuDelegate.h"

class MenuLayer;
class MenuScene : public cocos2d::Scene, public IMenuDelegate
{
public:
    // implement the "static create()" method manually
    CREATE_FUNC(MenuScene);
protected:
    // scene initialisation
    bool init() override;
    // scene shown
    void onEnter() override;
    // scene hidden
    void onExit() override;
    // called once per frame
    void update( float delta ) override;
    
private:
    //IMenuDelegate
    void onStartClicked() override;
    void onExitClicked() override;
    
private:
    MenuLayer* m_menuLayer = nullptr;
};

#endif //__MENU_SCENE_H__
