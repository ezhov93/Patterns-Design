#include "observerexample.h"
#include "QDebug"

ObserverExample::ObserverExample(QWidget *parent):QDialog(parent)
{
    layout = new QVBoxLayout;
    button = new QPushButton("Должен я это сделать?", this);
    layout->addWidget(button);
    setLayout(layout);

    connect(button, &QPushButton::released, [=](){
        qDebug()<<"Давай сделай это!";
    });

    connect(button, &QPushButton::released, [=](){
        qDebug()<<"Не делай это!";
    });
}

ObserverExample::~ObserverExample()
{
    delete button;
    delete layout;
}
