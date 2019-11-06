#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
using namespace std ;

class Cell {
public:
    int x, y;
    bool wall;
    bool visted;
    Cell() {}
};

class Maze {

    int width;
    int height;
    Cell **cells;
    stack <Cell> s ;
public:
    Maze(char *path)
    {
        int n ;
        ifstream infile(path) ;
        infile >> n ;
        bool maze [n][n] ;
        for (int a = 0 ; a < n ; a++)
            for (int b = 0 ; b < n ; b++)
                infile >> maze [a][b] ;
                width = n;
        height = n;

        cells = new Cell*[width];
        for(int i = 0; i < height; ++i)
            cells[i] = new Cell[width];

        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                Cell *cell = &cells[i][j];
                cell->x = i;
                cell->y = j;
                cell->wall = maze[i][j];
            }
        }

    }
    // Print the maze to stdout.
    void print()
    {
        cout << "MAZE ENTERED " << endl ;
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                if (cells[i][j].wall) {
                    std::cout << "1 ";
                } else {
                    std::cout << "0 ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }


    bool exitmaze(int x , int y)
    {


        if (x== width-1 && y == height-1)
        {
            s.push(cells[x][y]);
            return 1 ;
            cells[x][y].visted = 1 ;
        }

        if (x>=0 && x<width && y>=0&&y<height && cells[x][y].wall==0 && !cells[x][y].visted )
        {
            cells[x][y].visted = 1 ;
            s.push(cells[x][y]) ;
            if (exitmaze(x-1,y))
                return 1;
            if (exitmaze(x+1,y))
                return 1;
            if (exitmaze(x,y-1) )
                return 1;
            if (exitmaze(x,y+1))
                return 1;
            cells[x][y].visted = 0 ;
            s.pop();
        }
        return 0 ;
    }

    void printSol ()
    {
        queue <Cell> q ;
        while (!s.empty())
        {
            q.push(s.top()) ;
            s.pop() ;
        }

        while (!q.empty())
        {
            s.push(q.front()) ;
            q.pop() ;
        }

        Cell temp ;
        cout << "Solution by Stack" << endl ;
        while (!s.empty())
        {
            temp = s.top();
            s.pop() ;

            cout <<"(" << temp.x << "," << temp.y << "), "  ;

        }
        cout << endl <<endl ;


    }
};
