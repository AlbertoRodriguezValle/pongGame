#include <Player.hpp>

Player::Player(const PongGame &pongGame, unsigned int x, unsigned int y)
  : GameElement(pongGame, PLAYER_X_SIZE, PLAYER_Y_SIZE)
{
    setX(x);
    setY(y);
}

void Player::update()
{
      std::lock_guard<std::mutex> lock(mMutex);
      setY(getY() + static_cast<int>(mSpeedY));
}
