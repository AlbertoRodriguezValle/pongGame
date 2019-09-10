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

  }
  
  return true;
}
