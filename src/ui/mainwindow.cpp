#include "src/ui/mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <QPixmap>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      audioHandler_(std::make_shared<AudioHandler>())
{
    ui->setupUi(this);
    this->setFixedSize(1050, 650);

    audioHandler_->playMusic();
    game_ = (std::make_unique<BlackjackGame>(1000, audioHandler_, ui->gamePage,
                                             ui->dealerScoreLabel, ui->playerScoreLabel));

    gameBackground_.load(":/images/textures/gameBackground.jpg");
    mainMenuBackground_.load(":/images/textures/mainMenuBackground.jpg");

    ui->coin20Button->setStyleSheet("QPushButton { image: url(:/images/coins/20.png); "
                                    "background-color: transparent; }"
                                    "QPushButton::hover { border: 2px solid #ffffff; }"
                                    "QPushButton:pressed { background-color: #9c0000; }");

    ui->coin50Button->setStyleSheet("QPushButton { image: url(:/images/coins/50.png); "
                                    "background-color: transparent; }"
                                    "QPushButton::hover { border: 2px solid #ffffff; }"
                                    "QPushButton:pressed { background-color: #9c0000; }");

    ui->coin100Button->setStyleSheet("QPushButton { image: url(:/images/coins/100.png); "
                                     "background-color: transparent; }"
                                     "QPushButton::hover { border: 2px solid #ffffff; }"
                                     "QPushButton:pressed { background-color: #9c0000; }");

    ui->coin500Button->setStyleSheet("QPushButton { image: url(:/images/coins/500.png); "
                                     "background-color: transparent; }"
                                     "QPushButton::hover { border: 2px solid #ffffff; }"
                                     "QPushButton:pressed { background-color: #9c0000; }");

    ui->coin1000Button->setStyleSheet("QPushButton { image: url(:/images/coins/1000.png); "
                                      "background-color: transparent; }"
                                      "QPushButton::hover { border: 2px solid #ffffff; }"
                                      "QPushButton:pressed { background-color: #9c0000; }");

    ui->musicButton->setStyleSheet("image: url(:/images/icons/musicOn.svg) no-repeat; "
                                   "background-color: transparent;");

    ui->volumeButton->setStyleSheet("image: url(:/images/icons/volumeOn.svg) no-repeat; "
                                   "background-color: transparent;");

    ui->exitMainMenuButton->setStyleSheet("image: url(:/images/icons/exitMainMenu.svg) no-repeat; "
                                   "background-color: transparent;");

    ui->increaseBetButton->setStyleSheet("QToolButton { image: url(:/images/icons/plus.svg) no-repeat; "
                                         "background-color: transparent; }"
                                         "QToolButton:hover { border: 2px solid #ffffff; }"
                                         "QToolButton:pressed { background-color: #9c0000; }");

    ui->decreaseBetButton->setStyleSheet("QToolButton { image: url(:/images/icons/minus.svg) no-repeat; "
                                         "background-color: transparent; }"
                                         "QToolButton:hover { border: 2px solid #ffffff; }"
                                         "QToolButton:pressed { background-color: #9c0000; }");

    this->setStyleSheet("QLabel { background-color: transparent; color: #ffffff; font-weight: bold; }");

    ui->hitButton->setStyleSheet("QPushButton { background-color: #10c92f; color: #ffffff; font-weight: bold; "
                                 "border-top-right-radius: 15px; "
                                 "border-top-left-radius: 0px; "
                                 "border-bottom-right-radius: 0px; "
                                 "border-bottom-left-radius: 15px; }"
                                 "QPushButton::hover { border: 2px solid #ffffff; }"
                                 "QPushButton:pressed { background-color: #9c0000; }");

    ui->standButton->setStyleSheet("QPushButton { background-color: #10c92f; color: #ffffff; font-weight: bold; "
                                   "border-top-right-radius: 15px; "
                                   "border-top-left-radius: 0px; "
                                   "border-bottom-right-radius: 0px; "
                                   "border-bottom-left-radius: 15px; }"
                                   "QPushButton::hover { border: 2px solid #ffffff; }"
                                   "QPushButton:pressed { background-color: #9c0000; }");

    ui->dealButton->setStyleSheet("QPushButton { background-color: #10c92f; color: #ffffff; font-weight: bold; "
                                  "border-top-right-radius: 15px; "
                                  "border-top-left-radius: 0px; "
                                  "border-bottom-right-radius: 0px; "
                                  "border-bottom-left-radius: 15px; }"
                                  "QPushButton::hover { border: 2px solid #ffffff; }"
                                  "QPushButton:pressed { background-color: #9c0000; }");

    ui->newGameButton->setStyleSheet("QPushButton { background-color: #254b70; color: #ffffff; font-weight: bold; border-radius: 10px; }"
                                     "QPushButton::hover { border: 2px solid #ffffff; }"
                                     "QPushButton:pressed { background-color: #9c0000; }");

    ui->exitButton->setStyleSheet("QPushButton { background-color: #254b70; color: #ffffff; font-weight: bold; border-radius: 10px; }"
                                  "QPushButton::hover { border: 2px solid #ffffff; }"
                                  "QPushButton:pressed { background-color: #9c0000; }");

    ui->playerScoreLabel->setStyleSheet("image: url(:/images/textures/score.png);");
    ui->dealerScoreLabel->setStyleSheet("image: url(:/images/textures/score.png);");

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
        ui->musicButton->setStyleSheet("image: url(:/images/icons/musicOff.svg) no-repeat; "
                                       "background-color: transparent;");
        audioHandler_->stopMusic();
    }
    else {
        ui->musicButton->setStyleSheet("image: url(:/images/icons/musicOn.svg) no-repeat; "
                                       "background-color: transparent;");
        audioHandler_->playMusic();
    }
}


void MainWindow::on_volumeButton_clicked()
{
    if (audioHandler_->isSoundEffectsEnabled()) {
        ui->volumeButton->setStyleSheet("image: url(:/images/icons/volumeOff.svg) no-repeat; "
                                       "background-color: transparent;");
        audioHandler_->enableSoundEffects(false);
    }
    else {
        ui->volumeButton->setStyleSheet("image: url(:/images/icons/volumeOn.svg) no-repeat; "
                                       "background-color: transparent;");
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
    QString path = QFileDialog::getOpenFileName(nullptr, "Choose your skin", "", "Images (*.png *.jpg *.jpeg)");

    if (!path.isEmpty()) {
        game_->changeCardsSkin(path);
    }
}

