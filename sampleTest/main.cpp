#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int x=50;
    int y=50;

    while(1)
    {
        int r = rand() %4;
        switch (r) {
        case 0:
            break;

        }
    }
    return a.exec();
}
