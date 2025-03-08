#include <SFML/Graphics.hpp>
#include "src\Headers\Game.hpp"

int main()
{
   std::cout << "Current Working Directory: " << std::filesystem::current_path() << std::endl;
   Game game;

   game.run();
   
   return 0;
}