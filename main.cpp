#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Game2D.h"
#include "Board3D.h"


int main() { 
    char again;

    do {
        Game2D game;
        game.play();

        std::cout << "Play again? (y/n): ";
        std::cin >> again;
        again = std::tolower(again);

    } while (again == 'y');

    std::cout << "Thanks for playing!" << std::endl;
    return 0;



}
