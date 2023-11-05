QT       += core gui

QT += multimedia
QT += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/classbuttonmouser.cpp \
    src/classitemplay.cpp \
    src/classplaylistwidget.cpp \
    src/classppgraphicsview.cpp \
    src/funKeyEvent.cpp \
    src/funcConnect.cpp \
    src/funcInitializePlayer.cpp \
    src/funcLocalSetting.cpp \
    src/funcSlider.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/validsuffix.cpp

HEADERS += \
    src/classbuttonmouser.h \
    src/classitemplay.h \
    src/classplaylistwidget.h \
    src/classppgraphicsview.h \
    src/mainwindow.h \
    src/validsuffix.h

FORMS += \
    src/form/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
