//
//  SDLGameObject.cpp
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 19/01/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#include "ShooterObject.h"
#include "TextureManager.h"
#include "Game.h"

ShooterObject::ShooterObject() :    SDLGameObject(),
                                    m_bulletFiringSpeed(0),
                                    m_bulletCounter(0),
                                    m_moveSpeed(0),
                                    m_dyingTime(0),
                                    m_dyingCounter(0),
                                    m_bPlayedDeathSound(false)
{
}

void ShooterObject::doDyingAnimation()
{
    m_currentFrame = int(((SDL_GetTicks() / (1000/ 10)) % m_numFrames));
    
    if(m_dyingCounter == m_dyingTime)
    {
        m_bDead = true;
    }
    m_dyingCounter++;
}