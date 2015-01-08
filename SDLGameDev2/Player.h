//
//  Player.h
//  
//
//  Created by weimj on 15/1/8.
//
//

#ifndef ____Player__
#define ____Player__

#include <stdio.h>

#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
    Player();
    virtual void draw();
    virtual void update();
    virtual void clean();
};

#endif /* defined(____Player__) */
