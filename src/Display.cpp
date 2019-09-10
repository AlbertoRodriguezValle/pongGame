#include <iostream>
#include <Display.hpp>
#include <Player.hpp>

Display::Display(const PongGame &pongGame)
  : mPongGame(pongGame)
{
  
}

Display::~Display()
{

}

void Display::render()
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
  
  mSdlWindow = SDL_CreateWindow("Pong Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, mPongGame.getWidth(),
                                mPongGame.getHeight(), SDL_WINDOW_SHOWN);
  
  if (mSdlWindow == nullptr)
  {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  mSdlRenderer = SDL_CreateRenderer(mSdlWindow, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == mSdlRenderer)
  {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
  
  while(mRun)
  {
    SDL_Rect block;
    block.w = 5;
    block.h = 5;

    // Clear screen
    SDL_SetRenderDrawColor(mSdlRenderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(mSdlRenderer);

    SDL_SetRenderDrawColor(mSdlRenderer, 0x00, 0x7A, 0xCC, 0xFF);
    SDL_Rect player1;
    player1.w = Player::PLAYER_X_SIZE;
    player1.h = Player::PLAYER_Y_SIZE;
    unsigned int x;
    unsigned int y;
    mPongGame.getPlayer1Position(&x, &y);
    player1.x = static_cast<int>(x);
    player1.y = static_cast<int>(y) - Player::PLAYER_Y_SIZE / 2;
    //std::cerr << "Player 1: " << player1.x << "     " << player1.y << std::endl;
    SDL_RenderFillRect(mSdlRenderer, &player1);

    SDL_SetRenderDrawColor(mSdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_Rect player2;
    player2.w = -Player::PLAYER_X_SIZE;
    player2.h = Player::PLAYER_Y_SIZE;
    mPongGame.getPlayer2Position(&x, &y);
    player2.x = static_cast<int>(x);
    player2.y = static_cast<int>(y) - Player::PLAYER_Y_SIZE / 2;
    //std::cerr << "Player 2: " << player2.x << "     " << player2.y << std::endl;
    SDL_RenderFillRect(mSdlRenderer, &player2);

    SDL_SetRenderDrawColor(mSdlRenderer, 0xFF, 0xFF, 0x00, 0xFF);
    SDL_Rect ball;
    ball.w = 10;
    ball.h = 10;
    mPongGame.getBallPosition(&x, &y);
    ball.x = static_cast<int>(x);
    ball.y = static_cast<int>(y);
    //std::cerr << "Ball: " << ball.x << "     " << ball.y << std::endl;
    SDL_RenderFillRect(mSdlRenderer, &ball);

    SDL_SetRenderDrawColor(mSdlRenderer,  0xFF, 0xCC, 0x00, 0xFF);
    SDL_RenderDrawLine(mSdlRenderer, mPongGame.getWidth() / 2, 0, mPongGame.getWidth() / 2, mPongGame.getHeight());

    SDL_RenderPresent(mSdlRenderer);
  }
  
  SDL_DestroyWindow(mSdlWindow);
  SDL_Quit();
}

void Display::setRun(bool run)
{
  mRun = run;
}