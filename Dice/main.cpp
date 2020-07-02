#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <commondefine.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQuickView *mainView = new QQuickView();
    mainView->setFlags(Qt::FramelessWindowHint);

    mainView->setColor(QColor(Qt::transparent));
    mainView->setResizeMode(QQuickView::SizeViewToRootObject);
    mainView->setSource(QUrl("qrc:/main.qml"));
    mainView->show();
    mainView->setGeometry(QRect(WINDOW_X_POS, WINDOW_Y_POS, WINDOW_WIDTH_SIZE, WINDOW_HEIGHT_SIZE));
    mainView->setMinimumSize(QSize(WINDOW_WIDTH_SIZE, WINDOW_HEIGHT_SIZE));
    mainView->setMaximumSize(QSize(WINDOW_WIDTH_SIZE, WINDOW_HEIGHT_SIZE));

    return app.exec();
}
