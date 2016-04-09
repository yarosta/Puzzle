#include "puzzleview.h"
#include <QPushButton>

PuzzleView::PuzzleView(QWidget *parent) : QWidget(parent)
{
    srand(time(0));

    m_Model = new PuzzleModel();

    QHBoxLayout* main_Layout = new QHBoxLayout(this);

    m_Layout = new QGridLayout();

    for (int column=1; column<=4; column++)
    {
        for (int row=1; row<=4; row++)
        {
            int value;
            value = m_Model->value(row, column);
            m_Buttons.addButton(new Tile(value), value);
            m_Layout->addWidget(m_Buttons.button(value),row,column);
            m_Buttons.button(value)->setText(QString("%1").arg(value));
            connect(m_Buttons.button(value),SIGNAL(clicked()),this,SLOT(tryToSlide()));
        }
    }

    m_Buttons.button(0)->setVisible(false);

    connect(m_Model,SIGNAL(gridChanged()),this,SLOT(refresh()));

    QPushButton* shake_button = new QPushButton("Wymieszaj");
    QPushButton* exit_button = new QPushButton("Wyjdz");

    QVBoxLayout* button_layout = new QVBoxLayout();

    button_layout->addStretch(1);
    button_layout->addWidget(shake_button);
    button_layout->addWidget(exit_button);
    button_layout->addSpacing(20);

    main_Layout->addLayout(m_Layout);
    main_Layout->addStretch(0);
    main_Layout->addLayout(button_layout);

    connect(shake_button,SIGNAL(clicked()),this,SLOT(shake()));
    connect(exit_button,SIGNAL(clicked()),this->parent(),SLOT(close()));
    shake();
    connect(m_Model,SIGNAL(win()),this,SLOT(win()));


}

void PuzzleView::refresh()
{
    for(int id=0; id<=15; id++)
    {
        disconnect(m_Buttons.button(id),SIGNAL(clicked()),this,SLOT(tryToSlide()));
        delete m_Buttons.button(id);
    }
    for (int column=1; column<=4; column++)
    {
        for (int row=1; row<=4; row++)
        {
            int value;
            value = m_Model->value(row, column);
            m_Buttons.addButton(new Tile(value), value);
            m_Layout->addWidget(m_Buttons.button(value),row,column);
            m_Buttons.button(value)->setText(QString("%1").arg(value));
            connect(m_Buttons.button(value),SIGNAL(clicked()),this,SLOT(tryToSlide()));
        }
    }
     m_Buttons.button(0)->setVisible(false);
}

void PuzzleView::tryToSlide()
{
    Tile* button = dynamic_cast<Tile*>(QObject::sender());
    int tileNumber = button->getTileNumber();
    int newPosition;
    newPosition = m_Model->slide(tileNumber);
    if(newPosition == true) refresh();
}

void PuzzleView::shake()
{
    int counter;
    counter = 250;
    while(counter>0)
    {
        int tileNumber;
        tileNumber = rand()%15 +1;
        int newPosition;
        newPosition = m_Model->slide(tileNumber);
        if(newPosition == true)
        {
            counter--;
            refresh();
        }
    }
}

void PuzzleView::win()
{
    QMessageBox::information(this,"Zwycięstwo","Odnosisz zwycięstwo.");
}
