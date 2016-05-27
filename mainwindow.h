#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QBitmap>
#include <QMainWindow>
#include <QTimer>
#include <QAbstractButton>
#include <QPixmap>
#include <QMessageBox>
#include <QTableWidget>
#include <QDialog>
#include <QVector>
#include <QPair>
#include <QFile>
#include <QInputDialog>
#include <QTextStream>
#include <QCoreApplication>

#include "button.h"
#include "board.h"


const int MAPSIZE = 10;
const int OBS_SIZE = 20;
const int START_X = 0, START_Y = 0;
const int END_X = 0, END_Y = 9;

class Button;
class Board;

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

public slots:
    void gameStart();
    void quitSlot();
    void aboutSlot();
    void helpSlot();

private:
    Ui::MainWindow *ui;
    Button * mb[MAPSIZE][MAPSIZE];
    Board * board;
};

#endif // MAINWINDOW_H
