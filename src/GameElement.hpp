#ifndef GAMEELEMENT_HPP
#define GAMEELEMENT_HPP

#include <mutex>

enum class Speed {Positive = 1, Negative = -1, Zero = 0};
class PongGame;

class GameElement
{
 public:
  GameElement(const PongGame &pongGame, unsigned int sizeX, unsigned int sizeY);
  virtual void update() = 0;
  void setX(int x);
  void setY(int y);
  unsigned int getX() const;
  unsigned int getY() const;  
  void setSpeedX(Speed speed);
  void setSpeedY(Speed speed);
  std::mutex mMutex;
  
  protected:
    unsigned int mSizeX;
    unsigned int mSizeY;
    const PongGame &mPongGame;
    Speed mSpeedX = Speed::Zero;
    Speed mSpeedY = Speed::Zero;    
    
  private:
    unsigned int mX;
    unsigned int mY;
};

#endif