#ifndef TILE_H
#define TILE_H
#include <QPushButton>

class Tile : public QPushButton
{
public:
    Tile(int tileNumber, QWidget* parent=0);
    int getTileNumber();
private:
    int m_Number;
};

#endif // TILE_H
