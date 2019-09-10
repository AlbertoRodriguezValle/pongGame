#ifndef PONGGAME_HPP
#define PONGGAME_HPP

#include <memory>
#include <Ball.hpp>
#include <Player.hpp>

class PongGame
{
  public:
  PongGame(unsigned int width, unsigned int height);
  void update(void);
  void getBallPosition(unsigned int *x, unsigned int *y)  const;
  void getPlayer1Position(unsigned int *x, unsigned int *y)  const;
  void getPlayer2Position(unsigned int *x, unsigned int *y)  const;
  unsigned int getWidth() const;
  unsigned int getHeight() const;
  void setPlayer1Speed(Speed speed);
  void setPlayer2Speed(Speed speed);
  void waitForFinish();
  void execute();
  void setRun(bool run);
  
  
  private:
  unsigned int mWidth;
  unsigned int mHeight;
  std::unique_ptr<Player> mPlayer1;
  std::unique_ptr<Player> mPlayer2;
  std::unique_ptr<Ball> mBall;
  bool mRun = true;
  unsigned int mScorePlayer1 = 0;
  unsigned int mScorePlayer2 = 0;
  unsigned long long mCycle = 0;
};

#endif