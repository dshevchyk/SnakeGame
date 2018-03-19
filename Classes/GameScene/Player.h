//
//  Player.h
//  ExpJam
//
//  Created by dmytros on 3/19/18.
//

#ifndef Player_h
#define Player_h
#include "cocos2d.h"
class Snake;
enum class MoveDirection;
class Player
{
public:
    Player(Snake*);
    
    void play(cocos2d::Point);    //  play game
    
private:
    MoveDirection searchDirection(cocos2d::Point);  //  search next direction
    void adjustDirection(int);
    
    Snake* m_mySnake;
    cocos2d::Point m_headPosition;
    cocos2d::Point m_nexPosition;
    cocos2d::Rect m_upRect;
    cocos2d::Rect m_downRect;
    cocos2d::Rect m_rightRect;
    cocos2d::Rect m_leftRect;
};

#endif /* Player_h */
