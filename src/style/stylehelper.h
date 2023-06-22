#ifndef STYLEHELPER_H
#define STYLEHELPER_H

#include <QString>

class StyleHelper
{
public:
    StyleHelper();

    static QString getMainWindowStyle();
    static QString getCoinButtonStyle(int value);
    static QString getMusicOnButtonStyle();
    static QString getMusicOffButtonStyle();
    static QString getVolumeOnButtonStyle();
    static QString getVolumeOffButtonStyle();
    static QString getExitMainMenuButtonStyle();
    static QString getIncreaseButtonStyle();
    static QString getDecreaseButtonStyle();
    static QString getGameButtonStyle();
    static QString getMainMenuButtonStyle();
    static QString getScoreLabelStyle();

};

#endif // STYLEHELPER_H
