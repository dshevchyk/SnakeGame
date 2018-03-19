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
    
    Snake* m_mySnake;
};

#endif /* Player_h */
