#ifndef PUZZLEMODEL_H
#define PUZZLEMODEL_H

#include <QObject>

class PuzzleModel : public QObject
{
    Q_OBJECT
public:
    explicit PuzzleModel(QObject *parent = 0);
    int value(int row, int column);
    bool slide(int tilenum);
    int neighboring(int row, int column);
    void checkWin();
signals:
    void gridChanged();
    void win();
public slots:

private:
    QList<int> m_Positions;
};

#endif // PUZZLEMODEL_H
