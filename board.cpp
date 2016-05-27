#include "board.h"

// Dynamically create the board
Board::Board(int size, int obsnum, MainWindow * mainwindow)
{
    // locations with cost of movement 5 (high)
    forests = std::vector<Location> {
      L{3, 4}, L{3, 5}, L{4, 1}, L{4, 2},
      L{4, 3}, L{4, 4}, L{4, 5}, L{4, 6},
      L{4, 7}, L{4, 8}, L{5, 1}, L{5, 2},
      L{5, 3}, L{5, 4}, L{5, 5}, L{5, 6},
      L{5, 7}, L{5, 8}, L{6, 2}, L{6, 3},
      L{6, 4}, L{6, 5}, L{6, 6}, L{6, 7},
      L{7, 3}, L{7, 4}, L{7, 5}
    };
    this->mainwindow = mainwindow;
    x = size;
    y = size;

    cnt = obsnum;
    // Create the Square array
    Grid = new Square* [x];
    for(int i = 0; i < x ; ++i)
        Grid[i] = new Square [y];

    // Start the seed for our psuedo-random number
    srand(time(NULL));

//    // Populate the board with obstacles
//    int obsx = rand() % x, obsy = rand() % y;
//    for(int i = 0; i < cnt;){
//        obsx = rand() % x; // Choose our X cord
//        obsx =  rand() % y;	// Choose our Y cord

//        Button::icon_test = QIcon(QPixmap(":/res/image/num0.png"));
//        Button::icon_test.addPixmap(QPixmap(":/res/image/num0.png"),QIcon::Disabled);
//        if(!(obsx==7&&obsy==0)&&!(obsx==0&&obsy==9)&&!Grid[obsx][obsy].isObstacle){
//            Grid[obsx][obsy].isObstacle = true;

//        //   Grid[obsx][obsy].getButton()->setIcon(Button::icon_test);

//            ++i;
//        }
//    }

}



int Board::cost(Location from_node, Location to_node){

      return std::find(forests.begin(), forests.end(), to_node)!=forests.end() ? 1 : 1;  // can change cost for moving to certain cells viz. those in forest
}

std::vector<Location> Board::neighbors(Location pos){
  int xcord,ycord;
  std::tie(xcord,ycord) = pos;
  std::vector<Location> res;
  Square** grid = this->getGrid();
  for(signed int i = -1; i < 2; ++i){
      for(signed int j = -1; j < 2; ++j){
          if((i!=0||j!=0)&& ((xcord + i >= 0) && (ycord + j >= 0))
             && ((xcord + i < 10) && (ycord + j < 10))&&!grid[xcord+i][ycord+j].isObstacle){
            res.push_back(std::make_pair(xcord+i,ycord+j));
          }
      }
  }
return res;
}

Board::~Board()
{
    for(int i = 0; i < x; ++i)
        delete [] Grid[i];

    delete [] Grid;
}


// This will be called whenever a square is clicked
void Board::leftClickSquare(int xcord, int ycord)
{

    if(Grid[xcord][ycord].isObstacle || Grid[xcord][ycord].isFlipped)
        return;

    Grid[xcord][ycord].flip();
}



