#include <QtQuick3D/qquick3d.h>
#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>
#include <QResource>
#include <QSurfaceFormat>

int main(int argc, char* argv[]) {
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QSurfaceFormat::setDefaultFormat(QQuick3D::idealSurfaceFormat());

    QResource::registerResource("qml.rcc");

    QQuickView* view = new QQuickView;
    view->setSource(QUrl::fromLocalFile(":/MainWindow.qml"));
    view->show();

    return app.exec();
}
