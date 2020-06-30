#include <QGuiApplication>
#include <starter.h>
#include <QQuickView>

#define HUD_WINDOW_X_POS 1920
#define HUD_WINDOW_Y_POS 0
#define HUD_WINDOW_WIDTH_SIZE 800
#define HUD_WINDOW_HEIGHT_SIZE 640

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    const QUrl url(QStringLiteral("qrc:/main.qml"));
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [url](QObject *obj, const QUrl &objUrl) {
//        if (!obj && url == objUrl)
//            QCoreApplication::exit(-1);
//    }, Qt::QueuedConnection);
//    engine.load(url);

    QQuickView *mainView = new QQuickView();
    mainView->setFlags(Qt::FramelessWindowHint);

    mainView->setColor(QColor(Qt::transparent));
    mainView->setResizeMode(QQuickView::SizeViewToRootObject);
    mainView->setSource(QUrl("qrc:/main.qml"));
    mainView->show();
    mainView->setGeometry(QRect(HUD_WINDOW_X_POS, HUD_WINDOW_Y_POS, HUD_WINDOW_WIDTH_SIZE, HUD_WINDOW_HEIGHT_SIZE));
    mainView->setMinimumSize(QSize(HUD_WINDOW_WIDTH_SIZE, HUD_WINDOW_HEIGHT_SIZE));
    mainView->setMaximumSize(QSize(HUD_WINDOW_WIDTH_SIZE, HUD_WINDOW_HEIGHT_SIZE));

    Starter st;
    st.setEngine(mainView);

    st.init();


    return app.exec();
}
