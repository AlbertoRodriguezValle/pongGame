#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <mutex>
#include <GameElement.hpp>

class Player : public GameElement
{
  public:
    Player(const PongGame &pongGame, unsigned int x, unsigned int y);
    virtual void update();
    
    static const unsigned int PLAYER_X_SIZE = 10;
    static const unsigned int PLAYER_Y_SIZE = 60;
    
  protected:
    Speed mSpeed;
    
};

#endif