#include <Player.hpp>

Player::Player(const PongGame &pongGame, unsigned int x, unsigned int y)
  : GameElement(pongGame, PLAYER_X_SIZE, PLAYER_Y_SIZE)
{
}

void Player::update()
{
}
