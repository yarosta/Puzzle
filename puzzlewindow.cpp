#include "puzzlewindow.h"
#include "ui_puzzlewindow.h"

PuzzleWindow::PuzzleWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PuzzleWindow)
{
    ui->setupUi(this);
    puzzleView = new PuzzleView(this);
    setCentralWidget(puzzleView);
    this->setWindowTitle("Puzzle by yarosta");
    this->setWindowIcon(QIcon(":/puzzle.png"));
}

PuzzleWindow::~PuzzleWindow()
{
    delete ui;
}
