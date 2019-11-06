#include <iostream>
#include "maze.h"
#include <string>
#include <cstring>

int main(int argc, char **argv)
{
    // Commented out to facilitate testing.

    /*if (argc != 2) {
        std::cout << "USAGE: PathFinder <path>" << std::endl;
        return -1;
    }*/

    Maze maze ("input.txt");
    maze.print();
    if(maze.exitmaze(0,0))
    {
        cout << "Solutions" << endl ;

    }

    else
        cout << "No solution exists" << endl ;
    maze.printSol() ;
    return 0 ;

}
