//
//  SDLGameObject.cpp
//  
//
//  Created by weimj on 15/1/6.
//
//

#include "SDLGameObject.h"

#include "TextureManager.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) :
	GameObject(pParams),
	m_position(pParams->getX(), pParams->getY()),
	m_velocity(0,0)
{
    m_width = pParams->getWidth();
    m_height = pParams->getHeight();
    m_textureID = pParams->getTextureID();
    m_currentRow = 1;
    m_currentFrame = 1;
}

void SDLGameObject::draw()
{
    TextureManager::Instance()->drawFrame(m_textureID,
                                          (int)m_position.getX(), (int)m_position.getY(), m_width,
                                          m_height, m_currentRow, m_currentFrame,
                                          TheGame::Instance()->getRenderer());
}

void SDLGameObject::clean()
{
    
}

void SDLGameObject::update()
{
    m_velocity += m_acceleration;
    m_position += m_velocity;
}

Player::Player(const LoaderParams* pParams) :
SDLGameObject(pParams)
{
}

void Player::draw()
{
    SDLGameObject::draw(); // we now use SDLGameObject
}
void Player::update()
{
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
    m_acceleration.setX(1);
    SDLGameObject::update();
}
void Player::clean()
{
}

/////////Enemy//////////
Enemy::Enemy(const LoaderParams* pParams) :
SDLGameObject(pParams)
{
}

void Enemy::draw()
{
    SDLGameObject::draw(); // we now use SDLGameObject
}

void Enemy::update()
{
    m_position.setX(m_position.getX() + 1);
    m_position.setY(m_position.getY() + 1);
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::clean()
{
}