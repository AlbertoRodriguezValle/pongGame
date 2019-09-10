#include <iostream>

#include <GameElement.hpp>
#include <PongGame.hpp>

GameElement::GameElement(const PongGame &pongGame, unsigned int sizeX, unsigned int sizeY)
  : mPongGame(pongGame), mSizeX(sizeX), mSizeY(sizeY)
  {
  }
  
  void GameElement::setX(int x)
  {
    if ((mPongGame.getWidth() >= (x + mSizeX / 2)) && (0 <= (x - static_cast<int>(mSizeX) / 2)))
    {
      mX = x;
    }
  }
  
  void GameElement::setY(int y)
  {
    if ((mPongGame.getHeight() >= (y + mSizeY / 2)) && (0 <= (y - static_cast<int>(mSizeY) / 2)))
    {
      mY = y;
    }
  }
  
  unsigned int GameElement::getX() const
  {
    return mX;
  }
  
  unsigned int GameElement::getY() const
  {
    return mY;
  }
  
  void GameElement::setSpeedX(Speed speed)
  {
    std::lock_guard<std::mutex> lock(mMutex);
    mSpeedX = speed;
  }
  
  void GameElement::setSpeedY(Speed speed)
  {
    std::lock_guard<std::mutex> lock(mMutex);
    mSpeedY = speed;
  }