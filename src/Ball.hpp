#ifndef BALL_HPP
#define BALL_HPP

#include <GameElement.hpp>

class Ball : public GameElement
{
  public:
    Ball(const PongGame &pongGame, unsigned int x, unsigned int y);
    virtual void update();
    
  private:
};

#endif
