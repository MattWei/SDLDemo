//
//  game.cpp
//  
//
//  Created by weimj on 14/12/30.
//
//

#include "Game.h"

#include <iostream>

#include "LoaderParams.h"
#include "SDLGameObject.h"

Game* Game::s_pInstance = 0;

Game::Game()
	:m_pWindow(0),
	m_pRenderer(0),
	m_bRunning(false)
{

}

Game::~Game()
{
    if (m_bRunning) {
        m_bRunning = false;
    }
}

bool Game::init(const char* title, int xpos, int ypos, int width,
                int height, int flags)
{
    // attempt to initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) //SDL_INIT_EVERYTHING SDL_INIT_AUDIO | SDL_INIT_VIDEO
    {
        std::cout << "SDL init success\n";
    
        // init the window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos,
                                     width, height, flags);
        if(m_pWindow != 0) // window init success
        {
            std::cout << "window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            if(m_pRenderer != 0) // renderer init success
            {
                std::cout << "renderer creation success\n";
                if (!TheTextureManager::Instance()->load("../assets/animate-alpha.png",
                                                         "animate", m_pRenderer)) {
                    std::cout << "TextureManager load false\n";
                    return false;
                }
                
                std::cout << "TextureManager load image success\n";
                
                m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82,
                                                                    "animate")));
                m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82,
                                                                   "animate")));
                std::cout << "Create game object success\n";
                
            } else {
                std::cout << "renderer init fail\n";
                return false; // renderer init fail
            }
        } else {
            std::cout << "window init fail\n";
            return false; // window init fail
        }
    } else {
        std::cout << "SDL init fail:" << SDL_GetError() << std::endl;
        return false; // SDL init fail
    }
    
    std::cout << "init success\n";
    m_bRunning = true; // everything inited successfully, start the main loop
    
    return true;
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);
    
    // loop through our objects and draw them
    for(std::vector<GameObject*>::size_type i = 0; i !=
        m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
    
    SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
    for(std::vector<GameObject*>::size_type i = 0; i !=
        m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void Game::handleEvents()
{
    SDL_Event event;
    if(SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                m_bRunning = false;
                break;
            default:
            break;
        }
    }
}

void Game::clean()
{
    std::cout << "cleaning game\n";
    
    if (m_pWindow)
    	SDL_DestroyWindow(m_pWindow);
    
    if (m_pRenderer)
    	SDL_DestroyRenderer(m_pRenderer);
    
    SDL_Quit();
}


