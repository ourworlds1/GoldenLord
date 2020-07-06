#include <QCoreApplication>
#include <jsoninput.h>
#include <jsonparset.h>
#include <QString>
#include <QRandomGenerator>
#include <iostream>

using namespace  std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    JsonInput jsi;
    QString inputMessage = jsi.input();
    JsonParseT jspt;

    QRandomGenerator rg;
    for(int i=1; i<10; i++)
    {
        cout << rg.bounded(i) <<" ";
    }
    cout << endl;

    for(int i=1; i<10; i++)
    {
        cout << rg.bounded(i) <<" ";
    }
    cout << endl;
    vector<int> pl;
    for(int i=1; i<10; i++)
    {
        int temp =rg.bounded(60);
        cout << temp <<" ";
        pl.push_back(temp);
    }
    cout << endl;
    for(size_t i=0; i<pl.size(); i++)
    {
        cout << pl[i]%4 << " ";
    }
    cout << endl;

    pl.clear();
    for(int i=1; i<10; i++)
    {
        int temp =rg.bounded(60);
        cout << temp <<" ";
        pl.push_back(temp);
    }
    cout << endl;

    for(size_t i=0; i<pl.size(); i++)
    {
        cout << pl[i]%4 << " ";
    }
    cout << endl;




    return a.exec();
}
