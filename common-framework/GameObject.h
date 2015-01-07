//
//  GameObject.h
//  
//
//  Created by weimj on 15/1/6.
//
//

#ifndef ____GameObject__
#define ____GameObject__

#include "LoaderParams.h"

#include <stdio.h>

class GameObject
{
public:
    virtual void draw()=0;
    virtual void update()=0;
    virtual void clean()=0;
    
protected:
    GameObject(const LoaderParams* pParams) {}
    virtual ~GameObject() {}
};


#endif /* defined(____GameObject__) */
