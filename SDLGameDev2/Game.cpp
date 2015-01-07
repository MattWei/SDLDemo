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
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, , SDL_RENDERER_ACCELERATED);
            if(m_pRenderer != 0) // renderer init success
            {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(m_pRenderer, 0,0,0,255);
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
    
    // register the types for the game
    TheGameObjectFactory::Instance()->registerType("MenuButton", new MenuButtonCreator());
    
    // start the menu state
    m_pGameStateMachine = new GameStateMachine();
    m_pGameStateMachine->changeState(new MainMenuState());
    
    std::cout << "init success\n";
    m_bRunning = true; // everything inited successfully, start the main loop
    
    return true;
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);
    
    
    m_pGameStateMachine->render();
    
    
    SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
	m_pGameStateMachine->update();
}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
}

void Game::clean()
{
    std::cout << "cleaning game\n";
    
    TheInputHandler::Instance()->clean();
    
    m_pGameStateMachine->clean();
    
    delete m_pGameStateMachine;
    m_pGameStateMachine = 0;
    
    if (m_pWindow)
    	SDL_DestroyWindow(m_pWindow);
    
    if (m_pRenderer)
    	SDL_DestroyRenderer(m_pRenderer);
    
    SDL_Quit();
}


