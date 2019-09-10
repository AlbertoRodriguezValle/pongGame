#ifndef INPUT_H
#define INPUT_H

#include <PongGame.hpp>

class Input
{
  public:
  Input(PongGame &pongGame);
  bool receiveInputs() const;
  
  private:
  PongGame &mPongGame;
};

#endif
