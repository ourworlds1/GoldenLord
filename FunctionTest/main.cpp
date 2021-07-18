#include <QCoreApplication>
#include <QDebug>
#include <functional>
#include <iostream>
#include <string>

using namespace std;
class A {
    int c;

public:
    A(int c) : c(c) {}
    int some_func() {
        qDebug() << " 비상수 함수 :  " << ++c;
        return c;
    }

    int some_const_function() const {
        qDebug() << " 상수 함수 :  " << c;
        return c;
    }

    static void st() {}
};

auto f = [] { cout << "qwer" << endl; };

auto c = [](int v) { cout << v << "*6=" << v * 6 << endl; };

int main(int argc, char* argv[]) {
    QCoreApplication a(argc, argv);

    //    [] { cout << "foo" << endl; }();
    //    [](int v) { cout << v << "*6=" << v * 6 << endl; }(7);
    f();
    c(7);

    int64_t bb = 10;
    int64_t cc = 13;

    qDebug() << "bb-cc:" << bb - cc;

    return a.exec();
}
