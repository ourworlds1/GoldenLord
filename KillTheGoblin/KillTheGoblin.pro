TEMPLATE = app
QT += qml quick quick3d opengl
TARGET = app
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

DESTDIR = $$OUT_PWD

include($$PWD/Character/Character.pri)
RESOURCES += $$PWD/qml/qml.qrc

RCC_DIR     = $$DESTDIR/.qrc

RCC_COMPONENT.target= qml.rcc
RCC_COMPONENT.depends= $$PWD/qml/
RCC_COMPONENT.commands= rcc -binary $$PWD/qml/qml.qrc -o $$DESTDIR/qml.rcc

QMAKE_EXTRA_TARGETS+=RCC_COMPONENT
POST_TARGETDEPS+=qml.rcc

QMAKE_CLEAN += \
    $$DESTDIR/qml.rcc \

target.path = $$TARGET

rcc_component.files = $$DESTDIR/qml.rcc
rcc_component.CONFIG += no_check_exist
rcc_component.path = $$TARGET

INSTALLS += target rcc_component

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
