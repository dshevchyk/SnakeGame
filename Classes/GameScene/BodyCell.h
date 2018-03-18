//
//  BaseCell.h
//  ExpJam
//
//  Created by dmytros on 18/03/2018.
//
//

#ifndef __BodyCell_H__
#define __BodyCell_H__

#include "BaseCell.h"


class BodyCell: public BaseCell
{
public:
    CREATE_FUNC(BodyCell);
    const char* getSpriteName() const override;
    
};
#endif // __BodyCell_H__
