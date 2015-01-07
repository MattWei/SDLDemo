//
//  TextureManager.h
//  
//
//  Created by weimj on 15/1/6.
//
//

#ifndef ____TextureManager__
#define ____TextureManager__

#include <stdio.h>

#include <string>
#include <map>

#include <sdl.h>
#include "SDL_image.h"

class TextureManager {
private:
    std::map<std::string, SDL_Texture*> m_textureMap;
    static TextureManager* s_pInstance;
    
    TextureManager() {}
    ~TextureManager() {}
    
    TextureManager(const TextureManager&);
    TextureManager& operator=(const TextureManager&);
    
public:
    static TextureManager* Instance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new TextureManager();
            return s_pInstance;
        }
        return s_pInstance;
    }
    
    bool load(std::string fileName,std::string id,
              SDL_Renderer* pRenderer);
    
    // draw
    void draw(std::string id, int x, int y, int width, int
              height, SDL_Renderer* pRenderer, SDL_RendererFlip flip =
              SDL_FLIP_NONE);
    
    // drawframe
    void drawFrame(std::string id, int x, int y, int width, int
                   height, int currentRow, int currentFrame, SDL_Renderer*
                   pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    
    void drawTile(std::string id, int margin, int spacing, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer);
    
    std::map<std::string, SDL_Texture*> getTextureMap() { return m_textureMap; }
    
    void clearTextureMap();
    
    void clearFromTextureMap(std::string id);
};

typedef TextureManager TheTextureManager;

#endif /* defined(____TextureManager__) */
