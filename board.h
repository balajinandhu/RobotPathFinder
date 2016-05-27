#ifndef BOARD_H
#define BOARD_H
#include <unordered_set>
#include <tuple>
#include <vector>
#include <cstdlib>
#include <ctime>
typedef std::tuple<int,int> Location;
typedef Location L;
#include "square.h"
#include "mainwindow.h"
class MainWindow;
class Square;

class Board{

public:

    Board(int size, int obsnum, MainWindow * mainwindow);    // Constructor
    ~Board();                               // Desturctor
    void leftClickSquare(int x, int y);
    Square ** getGrid();
     std::vector<Location> forests;
     int cost(Location start, Location end);
     std::vector<Location> neighbors(Location pos);

private:
     int x, y, cnt;   // X co-ord, Y co-ord, count of obstacles
    Square **Grid;
    MainWindow * mainwindow;
};

inline Square ** Board::getGrid()
{
    return Grid;
}

#endif // BOARD_H
