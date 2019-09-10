#ifndef BALL_HPP
#define BALL_HPP

#include <GameElement.hpp>

class Ball : public GameElement
{
  public:
    Ball(const PongGame &pongGame, unsigned int x, unsigned int y);
    virtual void update();
    bool isGoal() const;
    void restartAfterGoal();
    unsigned int getPlayerScore() const;
    
  private:
    bool mGoal = false;
    unsigned int mStartX;
    unsigned int mStartY;
    unsigned int mPlayerScore = 0;
};

#endif