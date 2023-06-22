#include "audiohandler.h"

AudioHandler::AudioHandler()
    : musicPlayer_(std::make_unique<QMediaPlayer>()),
      audioOutput_(std::make_unique<QAudioOutput>()),
      сardPlaceSound_(loadSoundEffect(":/sfx/сardPlace.wav")),
      сoinClickSound_(loadSoundEffect(":/sfx/сoinClick.wav")),
      dealSound_(loadSoundEffect(":/sfx/deal.wav")),
      roundEndSound_(loadSoundEffect(":/sfx/roundEnd.wav")),
      gameOverSound_(loadSoundEffect(":/sfx/gameOver.wav")),
      winSound_(loadSoundEffect(":/sfx/win.wav")),
      lossSound_(loadSoundEffect(":/sfx/loss.wav")),
      tieSound_(loadSoundEffect(":/sfx/tie.wav")),
      soundEffectsEnabled_(true),
      musicEnabled_(true)
{
    musicPlayer_->setAudioOutput(audioOutput_.get());
    musicPlayer_->setSource(QUrl("qrc:/sfx/theme.mp3"));
    musicPlayer_->setLoops(QMediaPlayer::Infinite);
    audioOutput_->setVolume(0.1f);
}

std::unique_ptr<QSoundEffect> AudioHandler::loadSoundEffect(QString path)
{
    auto sound = std::make_unique<QSoundEffect>();
    sound->setSource(QUrl("qrc" + path));
    sound->setVolume(0.2f);
    return sound;
}

void AudioHandler::playSound(QSoundEffect& sound)
{
    if (soundEffectsEnabled_) {
        sound.play();
    }
}

void AudioHandler::playMusic()
{
    musicPlayer_->play();
    musicEnabled_ = true;
}

void AudioHandler::stopMusic()
{
    musicPlayer_->stop();
    musicEnabled_ = false;
}

void AudioHandler::enableSoundEffects(bool enable)
{
    soundEffectsEnabled_ = enable;
}

bool AudioHandler::isMusicPlaying()
{
    return musicEnabled_;
}

bool AudioHandler::isSoundEffectsEnabled()
{
    return soundEffectsEnabled_;
}

void AudioHandler::playCardPlaceSound()
{
    this->playSound(*сardPlaceSound_);
}

void AudioHandler::playCoinClickSound()
{
    this->playSound(*сoinClickSound_);
}

void AudioHandler::playDealSound()
{
    this->playSound(*dealSound_);
}

void AudioHandler::playRoundEndSound()
{
    this->playSound(*roundEndSound_);
}

void AudioHandler::playGameOverSound()
{
    this->playSound(*gameOverSound_);
}

void AudioHandler::playWinSound()
{
    this->playSound(*winSound_);
}

void AudioHandler::playLossSound()
{
    this->playSound(*lossSound_);
}

void AudioHandler::playTieSound()
{
    this->playSound(*tieSound_);
}
