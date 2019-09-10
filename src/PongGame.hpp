#ifndef PONGGAME_HPP
#define PONGGAME_HPP

#include <memory>

class PongGame
{
  public:
  PongGame(unsigned int width, unsigned int height);
  void update(void);
  
  private:
  unsigned int mWidth;
  unsigned int mHeight;
};

#endif
