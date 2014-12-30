//
//  game.h
//  
//
//  Created by weimj on 14/12/30.
//
//

#ifndef ____game__
#define ____game__

#include "SDL.h"

class Game
{
public:
    Game();
    ~Game();
    bool init(const char* title, int xpos, int ypos, int width,
                  int height, int flags);
    void render();
    
    void update() {}
    void handleEvents();
    void clean();
    bool running() { return m_bRunning; }
private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    bool m_bRunning;
};

#endif /* defined(____game__) */
