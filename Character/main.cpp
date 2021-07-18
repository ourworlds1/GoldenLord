#include <Human.h>
#include <QCoreApplication>
#include <QDebug>

int main(int argc, char* argv[]) {
    QCoreApplication a(argc, argv);

    Human* A = new Human(100, 20, 20, 20);
    Human* B = new Human(100, 30, 30, 30);

    qDebug() << "A Hp : " << A->getHp() << "B Hp :" << B->getHp();

    A->attck(B);

    qDebug() << "A Hp : " << A->getHp() << "B Hp :" << B->getHp();

    B->attck(A);

    qDebug() << "A Hp : " << A->getHp() << "B Hp :" << B->getHp();

    return a.exec();
}
