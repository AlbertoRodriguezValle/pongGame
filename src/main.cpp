#include <iostream>
#include <thread>
#include <unistd.h>
#include <Display.hpp>
#include <Input.hpp>
#include <PongGame.hpp>

int main(int argc, char* argv[])
{
  std::cout << "Test" << std::endl;
  PongGame pongGame(800, 400);
  Display display(pongGame);
  Input input(pongGame);
  std::thread displayThread(&Display::render, &display);
  std::thread gameThread(&PongGame::execute, &pongGame);
  
  while (input.receiveInputs())
  {
    pongGame.update();
  }
  
  pongGame.setRun(false);
  display.setRun(false);
  displayThread.join();
  gameThread.join();
  return 0;
}