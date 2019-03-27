#ifndef OBSERVEREXAMPLE_H
#define OBSERVEREXAMPLE_H

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>

class ObserverExample : public QDialog
{
    Q_OBJECT

public:
    explicit ObserverExample(QWidget *parent = nullptr);
    ~ObserverExample();

private:
    QVBoxLayout *layout;
    QPushButton *button;
};

#endif // OBSERVEREXAMPLE_H
