//
//  game.cpp
//  
//
//  Created by weimj on 14/12/30.
//
//

#include "Game.h"

#include <iostream>
using namespace std;

#include "LoaderParams.h"
#include "SDLGameObject.h"
#include "GameObjectFactory.h"

#include "InputHandler.h"
#include "MainMenuState.h"
#include "MenuButton.h"

Game* Game::s_pInstance = 0;

Game::Game():
m_pWindow(0),
m_pRenderer(0),
m_bRunning(false),
m_pGameStateMachine(0),
m_playerLives(3),
m_scrollSpeed(0.8),
m_bLevelComplete(false),
m_bChangingState(false)
{
    // add some level files to an array
    //m_levelFiles.push_back("assets/map1.tmx");
    //m_levelFiles.push_back("assets/map2.tmx");
    
    // start at this level
    //m_currentLevel = 1;
}

Game::~Game()
{
    // we must clean up after ourselves to prevent memory leaks
    m_pRenderer= 0;
    m_pWindow = 0;
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    
    // store the game width and height
    m_gameWidth = width;
    m_gameHeight = height;
    
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    // attempt to initialise SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout << "SDL init success\n";
        // init the window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        
        if(m_pWindow != 0) // window init success
        {
            cout << "window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);
            
            if(m_pRenderer != 0) // renderer init success
            {
                cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(m_pRenderer, 0,0,0,255);
            }
            else
            {
                cout << "renderer init fail\n";
                return false; // renderer init fail
            }
        }
        else
        {
            cout << "window init fail\n";
            return false; // window init fail
        }
    }
    else
    {
        cout << "SDL init fail\n";
        return false; // SDL init fail
    }

    
    //TheInputHandler::Instance()->initialiseJoysticks();
    
    // register the types for the game
    TheGameObjectFactory::Instance()->registerType("MenuButton", new MenuButtonCreator());
    //TheGameObjectFactory::Instance()->registerType("Player", new PlayerCreator());
    
    // start the menu state
    m_pGameStateMachine = new GameStateMachine();
    m_pGameStateMachine->changeState(new MainMenuState());
    
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


