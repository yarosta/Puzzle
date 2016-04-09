#include "puzzlemodel.h"

PuzzleModel::PuzzleModel(QObject *parent) : QObject(parent)
{
    for (int id=1; id<=15; id++)
    {
        m_Positions.append(id);
    }
    m_Positions.append(0);
}

int PuzzleModel::value(int row, int column)
{
    return m_Positions[(row-1)*4+column-1];
}

bool PuzzleModel::slide(int tilenum)
{
    int position;
    position = m_Positions.indexOf(tilenum);
    int row;
    int column;
    row = position/4+1;
    column = position%4+1;
    int slide;
    slide = neighboring(row, column);
    if (slide >= 0)
    {
        m_Positions.swap(position,slide);
        checkWin();
        return true;
    } else return false;
}

int PuzzleModel::neighboring(int row, int column)
{
    int holePosition = -1;
    if (row>1)
    {
        if (value(row-1,column) == 0) holePosition = (row-1-1)*4+column-1;
    }
    if (row<4)
    {
        if (value(row+1,column) == 0) holePosition = (row-1+1)*4+column-1;
    }
    if (column>1)
    {
        if (value(row,column-1) == 0) holePosition = (row-1)*4+column-1-1;
    }
    if (column<4)
    {
        if (value(row,column+1) == 0) holePosition = (row-1)*4+column-1+1;
    }
    return holePosition;
}

void PuzzleModel::checkWin()
{
    int counter;
    counter=0;
    int iter;
    iter=0;
    while(counter==iter&&iter<=14)
    {
        if(m_Positions[iter]==(iter+1)) counter++;
        iter++;
    }
    if (counter==15)
    {
        emit win();
    }
}
