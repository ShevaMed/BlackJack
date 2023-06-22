#include "src/ui/mainwindow.h"
#include "ui_mainwindow.h"
#include "src/style/stylehelper.h"

#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      audioHandler_(std::make_shared<AudioHandler>())
{
    ui->setupUi(this);
    this->setFixedSize(1050, 650);
    this->setStyleSheet(StyleHelper::getMainWindowStyle());

    audioHandler_->playMusic();
    game_ = (std::make_unique<BlackjackGame>(1000, audioHandler_, ui->gamePage,
                                             ui->dealerScoreLabel, ui->playerScoreLabel));

    gameBackground_.load(":/images/textures/gameBackground.jpg");
    mainMenuBackground_.load(":/images/textures/mainMenuBackground.jpg");

    ui->coin20Button->setStyleSheet(StyleHelper::getCoinButtonStyle(20));
    ui->coin50Button->setStyleSheet(StyleHelper::getCoinButtonStyle(50));
    ui->coin100Button->setStyleSheet(StyleHelper::getCoinButtonStyle(100));
    ui->coin500Button->setStyleSheet(StyleHelper::getCoinButtonStyle(500));
    ui->coin1000Button->setStyleSheet(StyleHelper::getCoinButtonStyle(1000));
    ui->increaseBetButton->setStyleSheet(StyleHelper::getIncreaseButtonStyle());
    ui->decreaseBetButton->setStyleSheet(StyleHelper::getDecreaseButtonStyle());

    ui->musicButton->setStyleSheet(StyleHelper::getMusicOnButtonStyle());
    ui->volumeButton->setStyleSheet(StyleHelper::getVolumeOnButtonStyle());
    ui->exitMainMenuButton->setStyleSheet(StyleHelper::getExitMainMenuButtonStyle());

    ui->hitButton->setStyleSheet(StyleHelper::getGameButtonStyle());
    ui->standButton->setStyleSheet(StyleHelper::getGameButtonStyle());
    ui->dealButton->setStyleSheet(StyleHelper::getGameButtonStyle());

    ui->newGameButton->setStyleSheet(StyleHelper::getMainMenuButtonStyle());
    ui->exitButton->setStyleSheet(StyleHelper::getMainMenuButtonStyle());

    ui->playerScoreLabel->setStyleSheet(StyleHelper::getScoreLabelStyle());
    ui->dealerScoreLabel->setStyleSheet(StyleHelper::getScoreLabelStyle());

    connect(ui->decreaseBetButton, &QPushButton::clicked, [this]() { updateBetBalanceLabels(-10); });
    connect(ui->increaseBetButton, &QPushButton::clicked, [this]() { updateBetBalanceLabels(10); });
    connect(ui->coin20Button, &QPushButton::clicked, [this]() { updateBetBalanceLabels(20); });
    connect(ui->coin50Button, &QPushButton::clicked, [this]() { updateBetBalanceLabels(50); });
    connect(ui->coin100Button, &QPushButton::clicked, [this]() { updateBetBalanceLabels(100); });
    connect(ui->coin500Button, &QPushButton::clicked, [this]() { updateBetBalanceLabels(500); });
    connect(ui->coin1000Button, &QPushButton::clicked, [this]() { updateBetBalanceLabels(1000); });

    connect(ui->exitButton, &QPushButton::clicked, this, &QWidget::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateBetBalanceLabels(int value)
{
    int newBetValue = ui->betLabel->text().toInt() + value;

    if (newBetValue <= game_->getBalance() && newBetValue >= 0) {
        audioHandler_->playCoinClickSound();
        ui->betLabel->setText(QString::number(newBetValue));
        int currBalanceValue = ui->balanceLabel->text().toInt();
        ui->balanceLabel->setText(QString::number(currBalanceValue - value));
    }
}

void MainWindow::initGame()
{
    ui->betLabel->setText(QString::number(0));
    ui->balanceLabel->setText(QString::number(game_->getBalance()));
}

void MainWindow::endGame()
{
    this->initGame();
    ui->stackedWidget->setCurrentWidget(ui->placeBetPage);

    if (game_->getBalance() <= 0) {
        audioHandler_->playGameOverSound();
        QMessageBox::information(nullptr, "Game over", "You don't have any money!");
        ui->stackedWidget->setCurrentWidget(ui->mainMenuPage);
    }
}

void MainWindow::on_newGameButton_clicked()
{
    game_->resetBalance();
    this->initGame();
    ui->stackedWidget->setCurrentWidget(ui->placeBetPage);
    this->update();
}


void MainWindow::on_dealButton_clicked()
{
    int bet = ui->betLabel->text().toInt();

    if (game_->placeBet(bet)) {
        ui->betGameLabel->setText(QString::number(bet));
        ui->balanceGameLabel->setText(QString::number(game_->getBalance()));

        ui->stackedWidget->setCurrentWidget(ui->gamePage);
        game_->start();
    }
}


void MainWindow::on_hitButton_clicked()
{
    if (!game_->playerHit()) {
        this->endGame();
    }
}


void MainWindow::on_standButton_clicked()
{
    game_->playerStand();
    this->endGame();
}


void MainWindow::on_musicButton_clicked()
{
    if (audioHandler_->isMusicPlaying()) {
        ui->musicButton->setStyleSheet(StyleHelper::getMusicOffButtonStyle());
        audioHandler_->stopMusic();
    }
    else {
        ui->musicButton->setStyleSheet(StyleHelper::getMusicOnButtonStyle());
        audioHandler_->playMusic();
    }
}


void MainWindow::on_volumeButton_clicked()
{
    if (audioHandler_->isSoundEffectsEnabled()) {
        ui->volumeButton->setStyleSheet(StyleHelper::getVolumeOffButtonStyle());
        audioHandler_->enableSoundEffects(false);
    }
    else {
        ui->volumeButton->setStyleSheet(StyleHelper::getVolumeOnButtonStyle());
        audioHandler_->enableSoundEffects(true);
    }
}


void MainWindow::on_exitMainMenuButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->mainMenuPage);
    this->update();
}


void MainWindow::on_actionSkin1_triggered()
{
    game_->changeCardsSkin(":/images/skins/skin1.png");
}


void MainWindow::on_actionSkin2_triggered()
{
    game_->changeCardsSkin(":/images/skins/skin2.png");
}


void MainWindow::on_actionSkin3_triggered()
{
    game_->changeCardsSkin(":/images/skins/skin3.png");
}


void MainWindow::on_actionLoadCustomSkin_triggered()
{
    QString path = QFileDialog::getOpenFileName(nullptr, "Choose your skin", "",
                                                "Images (*.png *.jpg *.jpeg)");
    if (!path.isEmpty()) {
        game_->changeCardsSkin(path);
    }
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    if (ui->stackedWidget->currentWidget() == ui->mainMenuPage) {
        painter.drawPixmap(rect(), mainMenuBackground_);
    }
    else {
        painter.drawPixmap(rect(), gameBackground_);
    }
}

