#include "SDL.h"
#include <Input.hpp>

Input::Input(PongGame &pongGame)
  : mPongGame(pongGame)
{
}

bool Input::receiveInputs() const
{
  SDL_Event event;
  bool running = true;
  while (SDL_PollEvent(&event))
  {
    if (event.type == SDL_QUIT)
    {
      running = false;
    }
    else if (event.type == SDL_KEYDOWN)
    {
      switch (event.key.keysym.sym) 
      {
        case SDLK_BACKSPACE:
          running = false;
          break;
        case SDLK_UP:
          mPongGame.setPlayer2Speed(Speed::Negative);
          break;
        case SDLK_DOWN:
          mPongGame.setPlayer2Speed(Speed::Positive);
          break;
        case SDLK_w:
          mPongGame.setPlayer1Speed(Speed::Negative);
          break;
        case SDLK_s:
          mPongGame.setPlayer1Speed(Speed::Positive);
          break;     
      }
    }
  }
  
  return running;  
}