#include "tile.h"

Tile::Tile(int tileNumber, QWidget* parent) : QPushButton(parent)
{
    m_Number = tileNumber;
}

int Tile::getTileNumber()
{
    return m_Number;
}
