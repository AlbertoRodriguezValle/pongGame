#include <Ball.hpp>
#include <Player.hpp>
#include <PongGame.hpp>

Ball::Ball(const PongGame &pongGame, unsigned int x, unsigned int y)
  : GameElement(pongGame, 5, 5), mStartX(x), mStartY(y)
{
    setX(x);
    setY(y);
}

void Ball::update()
{
      mGoal = false;
      mMutex.lock();
      setY(getY() + static_cast<int>(mSpeedY));
      setX(getX() + static_cast<int>(mSpeedX));
      mMutex.unlock();

      if (getX() + mSizeX / 2 == (mPongGame.getWidth() - static_cast<int>(Player::PLAYER_X_SIZE)))
      {
        unsigned int positionX;
        unsigned int positionY;
        mPongGame.getPlayer2Position(&positionX, &positionY);
        if ((positionY - Player::PLAYER_Y_SIZE) < getY() && (positionY + Player::PLAYER_Y_SIZE) > getY())
        {
          mSpeedX = Speed::Negative;
        }
        else
        {
          mGoal = true;
          mSpeedX = Speed::Zero;
          mSpeedY = Speed::Zero;
          mPlayerScore = 2;
        }    
      }
      else if (getX() - static_cast<int>(mSizeX) / 2 == Player::PLAYER_X_SIZE)
      {
        unsigned int positionX;
        unsigned int positionY;
        mPongGame.getPlayer1Position(&positionX, &positionY);
        if ((positionY - Player::PLAYER_Y_SIZE) < getY() && (positionY + Player::PLAYER_Y_SIZE) > getY())
        {
          mSpeedX = Speed::Positive;
        }
        else
        {
          mGoal = true;
          mSpeedX = Speed::Zero;
          mSpeedY = Speed::Zero;
          mPlayerScore = 1;
        }    
      }

      if (getY() + mSizeY / 2 == mPongGame.getHeight())
      {
        mSpeedY = Speed::Negative;
      }
      else if (getY() - static_cast<int>(mSizeY) / 2 == 0)
      {
        mSpeedY = Speed::Positive;
      }
}

bool Ball::isGoal() const
{
  return mGoal;
}

void Ball::restartAfterGoal()
{
  mSpeedX = (mPlayerScore == 1) ? Speed::Positive : Speed::Negative;
  mSpeedY = Speed::Negative;
  setX(mStartX);
  setY(mStartY);
  mGoal = false;
  mPlayerScore = 0;
}

unsigned int Ball::getPlayerScore() const
{
  return mPlayerScore;
}