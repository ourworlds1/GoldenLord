#include <Human.h>
#include <QCoreApplication>
#include <QDebug>

int main(int argc, char* argv[]) {
    QCoreApplication a(argc, argv);

    Human* A = new Human();
    Human* B = new Human();

    qDebug() << "A Hp : " << A->getHp() << "B Hp :" << B->getHp();

    A->attck(B);

    qDebug() << "A Hp : " << A->getHp() << "B Hp :" << B->getHp();

    B->attck(A);

    qDebug() << "A Hp : " << A->getHp() << "B Hp :" << B->getHp();

    return a.exec();
}
