#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<unordered_map>
#include "square.h"
#include "puzzle.cpp"
#include <new>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  // check if image library exists
  QFile file(":/res/image/flag30.png");
  if(!file.exists())
      QMessageBox::about (this, "Error", "Image not found.\nPlease copy the image folder to where the excutable is.");

  Button::icon_flag = QIcon(QPixmap(":/res/image/flag30.png"));
  Button::icon_flag.addPixmap(QPixmap(":/res/image/flag30.png"),QIcon::Disabled);
  Button::icon_blank = QIcon(QPixmap(":/res/image/blank30.png"));
  Button::icon_blank.addPixmap(QPixmap(":/res/image/blank30.png"),QIcon::Disabled);

  Button::icon_check = QIcon(QPixmap(":/res/image/check30.png"));
  Button::icon_check.addPixmap(QPixmap(":/res/image/check30.png"),QIcon::Disabled);

  Button::icon_check1 = QIcon(QPixmap(":/res/image/num0.png"));
  Button::icon_check1.addPixmap(QPixmap(":/res/image/num0.png"),QIcon::Disabled);

  board = NULL;
  setWindowTitle("Path Search Simulator");

  connect(ui->resetButton, SIGNAL(clicked()), this, SLOT(gameStart()));
  connect(ui->action_Reset, SIGNAL(triggered()), this, SLOT(gameStart()));
  connect(ui->actionE_Xit, SIGNAL(triggered()), this, SLOT(quitSlot()));
  connect(ui->action_About, SIGNAL(triggered()), this, SLOT(aboutSlot()));
  connect(ui->actionHelp, SIGNAL(triggered()), this, SLOT(helpSlot()));

  Button::mainwindow = this;
  ui->mapLayout->setSpacing(0);
  ui->mapLayout->setMargin(0);
  QSize iconSize(60,50);

  QPixmap resetButton (":/res/image/reset50.png");
  ui->resetButton->setIcon(QIcon(resetButton));
  ui->resetButton->setMask(resetButton.mask());
  ui->resetButton->setIconSize(iconSize);
  int count=0;
  int obsx = rand() % 10, obsy = rand() % 10;
  for(int i = 0; i < MAPSIZE; i++){
      for(int j = 0; j < MAPSIZE; j++){
          mb[i][j] = new (std::nothrow) Button(i, j);
          if(mb[i][j]==NULL){
            QMessageBox::about (NULL, "i"+QString::number(i)+" "+"j"+QString::number(j)+"Memory error", "Press Restart Again!!");
            }
          mb[i][j]->setFixedSize(30,30);
          QSize iconSize(30, 30);
          mb[i][j]->setIconSize(iconSize);

          if(count<OBS_SIZE&&((i%2==0)||(j%2==0))){
              mb[i][j]->setIcon(Button::icon_check1);
              count++;
            }
          else
            mb[i][j]->setIcon(Button::icon_blank);
            ui->mapLayout->addWidget(mb[i][j], i, j);
      }
  }

  gameStart();

}

MainWindow::~MainWindow()
{
    delete ui;
    for(int i = 0; i < MAPSIZE; i++){
        for(int j = 0; j < MAPSIZE; j++){
            delete mb[i][j];
        }
    }
}


// when the reset button is pressed
void MainWindow::gameStart()
{
    if(board != NULL)
        delete board;
   // ui->resetButton->setEnabled(false);

    board = new Board(MAPSIZE, OBS_SIZE, this);
    if(board==NULL){
      QMessageBox::about (NULL, "Game Over", "Press Reset Again!!");
      }
    Square** grid = board->getGrid();

    Button::board = this->board;
    int minex = (rand() % 3)+2, miney = (rand() % 3)+2;
    int count=0;
    for(int i = 0; i < MAPSIZE; i++){
        for(int j = 0; j < MAPSIZE; j++){
            mb[i][j]->setEnabled(true);
            mb[i][j]->setSquare(&grid[i][j]);
            if(!(i==START_X&&j==START_Y)&&!(i==END_X&&j==END_Y)&&count<OBS_SIZE&&((i%minex==0)&&(j%miney==0))){
                mb[i][j]->setIcon(Button::icon_check1);
                grid[i][j].isObstacle = true;
                count++;
              }
            else
                mb[i][j]->setIcon(Button::icon_blank);

            grid[i][j].setButton(mb[i][j]);
        }
    }
    mb[START_X][START_Y]->setIcon(Button::icon_check); //start
    grid[START_X][START_Y].setButton(mb[START_X][START_Y]);
    mb[END_X][END_Y]->setIcon(Button::icon_flag); //target
    grid[END_X][END_Y].setButton(mb[END_X][END_Y]);

    unordered_map<Location, Location> came_from;
    unordered_map<Location, int> cost_so_far;

   a_star_search(Location{START_X,START_Y}, Location{END_X,END_Y}, came_from, cost_so_far);
}


void MainWindow::quitSlot()
{
    qApp->quit();
}

// display about dialog
void MainWindow::aboutSlot()
{
    QString s("This QT app is made by Balaji Narayanaswami\n");
    s += "for Symbio Robotics Challenge.";
    QMessageBox::about (this, "About", s);
}

// display help dialog
void MainWindow::helpSlot()
{
    QString s("Left click on reset button to change the orientation of the obstacles.\n");
    QMessageBox::about (this, "Help", s);
}


