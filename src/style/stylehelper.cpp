#include "stylehelper.h"

StyleHelper::StyleHelper()
{

}

QString StyleHelper::getMainWindowStyle()
{
    return "QLabel { "
           "background-color: transparent; "
           "color: #ffffff; font-weight: bold; }";
}

QString StyleHelper::getCoinButtonStyle(int value)
{
    return "QPushButton { "
           "image: url(:/images/coins/" + QString::number(value) + ".png);"
           "background-color: transparent; }"
           "QPushButton::hover { border: 2px solid #ffffff; }"
           "QPushButton:pressed { background-color: #9c0000; }";
}

QString StyleHelper::getMusicOnButtonStyle()
{
    return "image: url(:/images/icons/musicOn.svg) no-repeat;"
           "background-color: transparent;";
}

QString StyleHelper::getMusicOffButtonStyle()
{
    return "image: url(:/images/icons/musicOff.svg) no-repeat;"
           "background-color: transparent;";
}

QString StyleHelper::getVolumeOnButtonStyle()
{
    return "image: url(:/images/icons/volumeOn.svg) no-repeat;"
           "background-color: transparent;";
}

QString StyleHelper::getVolumeOffButtonStyle()
{
    return "image: url(:/images/icons/volumeOff.svg) no-repeat;"
           "background-color: transparent;";
}

QString StyleHelper::getExitMainMenuButtonStyle()
{
    return "image: url(:/images/icons/exitMainMenu.svg) no-repeat;"
           "background-color: transparent;";
}

QString StyleHelper::getIncreaseButtonStyle()
{
    return "QToolButton { image: url(:/images/icons/plus.svg) no-repeat;"
           "background-color: transparent; }"
           "QToolButton:hover { border: 2px solid #ffffff; }"
           "QToolButton:pressed { background-color: #9c0000; }";
}

QString StyleHelper::getDecreaseButtonStyle()
{
    return "QToolButton { image: url(:/images/icons/minus.svg) no-repeat;"
           "background-color: transparent; }"
           "QToolButton:hover { border: 2px solid #ffffff; }"
           "QToolButton:pressed { background-color: #9c0000; }";
}

QString StyleHelper::getGameButtonStyle()
{
    return "QPushButton { "
           "background-color: #10c92f;"
           "color: #ffffff; font-weight: bold;"
           "border-top-right-radius: 15px;"
           "border-top-left-radius: 0px;"
           "border-bottom-right-radius: 0px;"
           "border-bottom-left-radius: 15px; }"
           "QPushButton:hover { border: 2px solid #ffffff; }"
           "QPushButton:pressed { background-color: #9c0000; }";
}

QString StyleHelper::getMainMenuButtonStyle()
{
    return "QPushButton { "
           "background-color: #254b70;"
           "color: #ffffff; font-weight: bold;"
           "border-radius: 10px; }"
           "QPushButton:hover { border: 2px solid #ffffff; }"
           "QPushButton:pressed { background-color: #9c0000; }";
}

QString StyleHelper::getScoreLabelStyle()
{
    return "image: url(:/images/textures/score.png);";
}
