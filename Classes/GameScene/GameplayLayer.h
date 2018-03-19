//
//  GameplayLayer.h
//  ExpJam
//
//  Created by dmytros on 18/03/2018.
//
//

#ifndef __GAMEPLAY_LAYER_H__
#define __GAMEPLAY_LAYER_H__

#include "cocos2d.h"
#include "DefaultConfiguration.h"
class Snake;
class Food;
enum class MoveDirection;
class GameplayLayer : public cocos2d::Layer
{
public:
    // implement the "static create()" method manually
    CREATE_FUNC(GameplayLayer);
    void setDirection(MoveDirection direction);
protected:
    // scene initialisation
    bool init() override;
    // scene shown
    void onEnter() override;
    // scene hidden
    void onExit() override;
    // called once per frame
    void update( float delta ) override;
    //add food object to layer
    void addFood();
private:
    Snake* m_snake = nullptr;
    Food* m_food = nullptr;
    float m_currentSpeed = DefaultConfiguration::speed;
};

#endif //__GAMEPLAY_LAYER_H__
