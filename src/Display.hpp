#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "SDL.h"

#include <PongGame.hpp>

class Display
{
  public:
    Display(const PongGame &pongGame);
    ~Display();
    void render();
    void setRun(bool run);
  
  private:
    SDL_Window *mSdlWindow;
    SDL_Renderer *mSdlRenderer;
    const PongGame &mPongGame;
    
    int mWidth = 0;
    int mHeight = 0;
    int mResolution = 1;
    bool mRun = true;
};

#endif
