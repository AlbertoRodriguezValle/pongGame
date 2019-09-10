#include <iostream>

#include <GameElement.hpp>
#include <PongGame.hpp>

GameElement::GameElement(const PongGame &pongGame, unsigned int sizeX, unsigned int sizeY)
  : mPongGame(pongGame), mSizeX(sizeX), mSizeY(sizeY)
  {
  }
  
