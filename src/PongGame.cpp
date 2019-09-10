#include <iostream>
#include <unistd.h>
#include <PongGame.hpp>

PongGame::PongGame(unsigned int width, unsigned int height)
  : mWidth(width), mHeight(height)
{
    mPlayer1 = std::unique_ptr<Player>(new Player(*this, 15, mHeight / 2));
    mPlayer2 = std::unique_ptr<Player>(new Player(*this, mWidth - 15, mHeight / 2));
    mBall = std::unique_ptr<Ball>(new Ball(*this, mWidth / 2, mHeight / 2));
    mBall->setSpeedX(Speed::Positive);
    mBall->setSpeedY(Speed::Negative);   
}

void PongGame::update(void)
{
  usleep(5000);
  mPlayer1->update();
  mPlayer2->update();
  if (mCycle % 2)
  {
    mBall->update();
  }
  
  mCycle++;
  
  if (mBall->isGoal())
  {
    if (mBall->getPlayerScore() == 1)
    {
      mScorePlayer1++;
    }
    else
    {
      mScorePlayer2++;
    }
    
    std::cout << "GOAL  !!!  - (Player 1: " << mScorePlayer1 << " - Player2: " << mScorePlayer2 << ")" << std::endl;
    mBall->restartAfterGoal();
  }  
}

void PongGame::getBallPosition(unsigned int *x, unsigned int *y) const
{
  mBall->mMutex.lock();
  *x = mBall->getX();
  *y = mBall->getY();
  mBall->mMutex.unlock();
}

void PongGame::getPlayer1Position(unsigned int *x, unsigned int *y)  const
{
  mPlayer1->mMutex.lock();
  *x = mPlayer1->getX();
  *y = mPlayer1->getY();
  mPlayer1->mMutex.unlock();
}

void PongGame::getPlayer2Position(unsigned int *x, unsigned int *y)  const
{
  mPlayer2->mMutex.lock();
  *x = mPlayer2->getX();
  *y = mPlayer2->getY();
  mPlayer2->mMutex.unlock();
}

unsigned int PongGame::getWidth() const
{
  return mWidth;
}

unsigned int PongGame::getHeight() const
{
  return mHeight;
}

void PongGame::setPlayer1Speed(Speed speed)
{
  mPlayer1->setSpeedY(speed);
}

void PongGame::setPlayer2Speed(Speed speed)
{
  mPlayer2->setSpeedY(speed);
}

void PongGame::execute()
{
  while(mRun)
  {
    update();
  }
}

void PongGame::setRun(bool run)
{
  mRun = run;
}