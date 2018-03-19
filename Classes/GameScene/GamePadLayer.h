//
//  GamePadLayer.h
//  ExpJam
//
//  Created by dmytros on 18/03/2018.
//
//

#ifndef __GAMEPad_LAYER_H__
#define __GAMEPad_LAYER_H__

#include "DefaultConfiguration.h"
#include "MoveDirection.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
class IGamePadDelegate;
class GamePadLayer : public cocos2d::Layer
{
public:
    // implement the "static create()" method manually
    CREATE_FUNC(GamePadLayer);
    
    void setDelegate(IGamePadDelegate* delegate);
    const IGamePadDelegate* getDelegate() const;
protected:
    // scene initialisation
    bool init() override;
    // scene shown
    void onEnter() override;
    // scene hidden
    void onExit() override;
    cocos2d::ui::Button* addControlBotton(MoveDirection direction);
private:
    IGamePadDelegate* m_delegate = nullptr;
};

#endif //__GAMEPad_LAYER_H__
