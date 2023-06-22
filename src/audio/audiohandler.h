#ifndef AUDIOHANDLER_H
#define AUDIOHANDLER_H

#include <QAudioOutput>
#include <QMediaPlayer>
#include <QSoundEffect>

class AudioHandler
{
public:
    AudioHandler();

    std::unique_ptr<QSoundEffect> loadSoundEffect(QString path);

    void playSound(QSoundEffect& sound);
    void playMusic();
    void stopMusic();

    void enableSoundEffects(bool enable);

    bool isMusicPlaying();
    bool isSoundEffectsEnabled();

    void playCardPlaceSound();
    void playCoinClickSound();
    void playDealSound();

    void playRoundEndSound();
    void playGameOverSound();

    void playWinSound();
    void playLossSound();
    void playTieSound();

private:
    std::unique_ptr<QMediaPlayer> musicPlayer_;
    std::unique_ptr<QAudioOutput> audioOutput_;
    std::unique_ptr<QSoundEffect> сardPlaceSound_, сoinClickSound_, dealSound_;
    std::unique_ptr<QSoundEffect> roundEndSound_, gameOverSound_;
    std::unique_ptr<QSoundEffect> winSound_, lossSound_, tieSound_;
    bool soundEffectsEnabled_;
    bool musicEnabled_;

};

#endif // AUDIOHANDLER_H
