//
//  GameScene.h
//  ExpJam
//
//  Created by dmytros on 18/03/2018.
//
//

#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "IGamePadDelegate.h"

class GameplayLayer;
class GamePadLayer;
class GameScene : public cocos2d::Scene, public IGamePadDelegate
{
public:
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
protected:
    // scene initialisation
    bool init() override;
    // scene shown
    void onEnter() override;
    // scene hidden
    void onExit() override;
    // called once per frame
    void update( float delta ) override;
    
    void onGamePadClicked(MoveDirection direction) override;
    
private:
    GameplayLayer* m_GameplayLayer = nullptr;
    GamePadLayer* m_GamePadLayer = nullptr;
};

#endif //__GAME_SCENE_H__
