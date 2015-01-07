//
//  SDLGameObject.h
//  
//
//  Created by weimj on 15/1/6.
//
//

#ifndef ____SDLGameObject__
#define ____SDLGameObject__

#include <stdio.h>

#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public:
    SDLGameObject(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    
protected:
    int m_width;
    int m_height;
    int m_currentRow;
    int m_currentFrame;
    
    std::string m_textureID;
    
    Vector2D m_position; //位置
    Vector2D m_velocity; //速度
    Vector2D m_acceleration; //加速度
};


class Player : public SDLGameObject
{
public:
    Player(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
};
// Enemy class
class Enemy : public SDLGameObject
{
public:
    Enemy(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
};

#endif /* defined(____SDLGameObject__) */
