#ifndef STARTER_H
#define STARTER_H

#include <QObject>
#include <QQuickView>

class Starter : public QObject
{
public:
    Starter();

    void display();
    void setEngine(QQuickView *v);

    void init();
    void movestart();


private:
    QQuickView *view;
};

#endif // STARTER_H
