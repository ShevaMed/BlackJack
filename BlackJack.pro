QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/audio/audiohandler.cpp \
    src/gamelogic/blackjackgame.cpp \
    src/gamelogic/card.cpp \
    src/gamelogic/deck.cpp \
    src/gamelogic/hand.cpp \
    src/gamelogic/igame.cpp \
    src/main.cpp \
    src/style/stylehelper.cpp \
    src/ui/mainwindow.cpp

HEADERS += \
    src/audio/audiohandler.h \
    src/gamelogic/blackjackgame.h \
    src/gamelogic/card.h \
    src/gamelogic/deck.h \
    src/gamelogic/hand.h \
    src/gamelogic/igame.h \
    src/style/stylehelper.h \
    src/ui/mainwindow.h

FORMS += \
    src/ui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
     \
    resources.qrc
