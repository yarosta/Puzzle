#ifndef PUZZLEVIEW_H
#define PUZZLEVIEW_H

#include <QWidget>
#include <QGridLayout>
#include <QButtonGroup>
#include <QMessageBox>
#include "tile.h"
#include "puzzlemodel.h"
#include <time.h>

class PuzzleView : public QWidget
{
    Q_OBJECT
public:
    explicit PuzzleView(QWidget *parent = 0);
signals:

public slots:
    void refresh();
    void tryToSlide();
    void shake();
    void win();
private:
    PuzzleModel* m_Model;
    QGridLayout* m_Layout;
    QButtonGroup m_Buttons;
};

#endif // PUZZLEVIEW_H
