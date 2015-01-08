//
//  Enemy.h
//  
//
//  Created by weimj on 15/1/8.
//
//

#ifndef ____Enemy__
#define ____Enemy__

#include <stdio.h>

#include "SDLGameObject.h"

// Enemy class
class Enemy : public SDLGameObject
{
public:
    Enemy();
    virtual void draw();
    virtual void update();
    virtual void clean();
};

#endif /* defined(____Enemy__) */
