#ifndef GAMEELEMENT_HPP
#define GAMEELEMENT_HPP

enum class Speed {Positive = 1, Negative = -1, Zero = 0};
class PongGame;

class GameElement
{
 public:
  GameElement(const PongGame &pongGame, unsigned int sizeX, unsigned int sizeY);
  virtual void update() = 0;
  
};

#endif
