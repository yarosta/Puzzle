#ifndef PUZZLEWINDOW_H
#define PUZZLEWINDOW_H

#include <QMainWindow>
#include "puzzleview.h"

namespace Ui {
class PuzzleWindow;
}

class PuzzleWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PuzzleWindow(QWidget *parent = 0);
    ~PuzzleWindow();

private:
    Ui::PuzzleWindow *ui;
    PuzzleView* puzzleView;
};

#endif // PUZZLEWINDOW_H
