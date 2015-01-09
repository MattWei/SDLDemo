//
//  main.cpp
//  SDLGameDemo
//
//  Created by weimj on 14/12/30.
//  Copyright (c) 2014年 weimj. All rights reserved.
//

#include "Game.h"

#include <iostream>

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

// our Game object

int main(int argc, char* argv[])
{
    Uint32 frameStart, frameTime;
    
    if (TheGame::Instance()->init("Chapter 1", 100, 100, 640, 480, 0) == false) {
        std::cout << "Game init false!" << std::endl;
    }
        
    while(TheGame::Instance()->running())
    {
        frameStart = SDL_GetTicks();
        
        TheGame::Instance()->handleEvents(); //Handle input
        TheGame::Instance()->update(); //Update the status
        TheGame::Instance()->render(); //Draw
        
        frameTime = SDL_GetTicks() - frameStart;
        if(frameTime< DELAY_TIME)
        {
            SDL_Delay((int)(DELAY_TIME - frameTime));
        }
    }
    
    TheGame::Instance()->clean();
    
    return 0;
}
