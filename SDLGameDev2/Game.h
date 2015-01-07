//
//  game.h
//  
//
//  Created by weimj on 14/12/30.
//
//

#ifndef ____game__
#define ____game__

#include "TextureManager.h"

#include <vector>
#include <SDL.h>

#include "GameObject.h"

class Game
{
public:
    static Game* Instance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new Game();
            return s_pInstance;
        }
        return s_pInstance;
    }
    

    bool init(const char* title, int xpos, int ypos, int width,
                  int height, int flags);
    void render();
    
    void update();
    void handleEvents();
    void clean();
    bool running() { return m_bRunning; }
    
    SDL_Renderer* getRenderer() const { return m_pRenderer; }
    
    SDL_Renderer* getRenderer() const { return m_pRenderer; }
    SDL_Window* getWindow() const { return m_pWindow; }
    GameStateMachine* getStateMachine() { return m_pGameStateMachine; }
    
    void quit() { m_bRunning = false; }
    
    int getGameWidth() const { return m_gameWidth; }
    int getGameHeight() const { return m_gameHeight; }
    float getScrollSpeed() { return m_scrollSpeed; }
    
    bool changingState() { return m_bChangingState; }
    void changingState(bool cs) { m_bChangingState = cs; }
    
private:
    Game();
    ~Game();
    Game(const Game&);
    Game& operator=(const Game&);
    
    static Game* s_pInstance;
    
    int m_currentFrame;
    
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    bool m_bRunning;
    
    std::vector<GameObject*> m_gameObjects;
    
    int m_gameWidth;
    int m_gameHeight;
    float m_scrollSpeed;
    
    GameStateMachine* m_pGameStateMachine;
};

typedef Game TheGame;

#endif /* defined(____game__) */
