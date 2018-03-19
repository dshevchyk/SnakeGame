//
//  MoveDirection.h
//  ExpJam
//
//  Created by dmytros on 3/18/18.
//

#ifndef MoveDirection_h
#define MoveDirection_h

enum class MoveDirection
{
    Up = 0,
    Right = 90,
    Down = 180,
    Left = 270,
};

struct MoveDirectionHelpder {
    static MoveDirection GetOppositeDirection( MoveDirection direction) {
        switch(direction)
        {
            case MoveDirection::Up: return MoveDirection::Down;
            case MoveDirection::Down: return MoveDirection::Up;
            case MoveDirection::Left: return MoveDirection::Right;
            case MoveDirection::Right: return MoveDirection::Left;
        }
    }
};
#endif /* MoveDirection_h */
