#include <Ball.hpp>
#include <Player.hpp>
#include <PongGame.hpp>

Ball::Ball(const PongGame &pongGame, unsigned int x, unsigned int y)
  : GameElement(pongGame, 5, 5)
{
}

void Ball::update()
{
}
