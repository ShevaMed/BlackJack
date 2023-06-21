#include "src/ui/mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1050, 650);

    game_ = (std::make_unique<BlackjackGame>(1000, ui->gamePage));

    backgroundImage_.load(":/images/textures/gameBackground.jpg");

    ui->coin20Button->setStyleSheet("image: url(:/images/coins/20.png); "
                                    "background-color: transparent;");
    ui->coin50Button->setStyleSheet("image: url(:/images/coins/50.png); "
                                    "background-color: transparent;");
    ui->coin100Button->setStyleSheet("image: url(:/images/coins/100.png); "
                                    "background-color: transparent;");
    ui->coin500Button->setStyleSheet("image: url(:/images/coins/500.png); "
                                    "background-color: transparent;");
    ui->coin1000Button->setStyleSheet("image: url(:/images/coins/1000.png); "
                                    "background-color: transparent;");

    ui->musicButton->setStyleSheet("image: url(:/images/icons/musicOn.svg) no-repeat; "
                                   "background-color: transparent;");

    ui->volumeButton->setStyleSheet("image: url(:/images/icons/volumeOn.svg) no-repeat; "
                                   "background-color: transparent;");

    ui->exitMainMenuButton->setStyleSheet("image: url(:/images/icons/exitMainMenu.svg) no-repeat; "
                                   "background-color: transparent;");

    this->setStyleSheet("QLabel { background-color: transparent; color: #ffffff; font-weight: bold; }");

    ui->hitButton->setStyleSheet("QPushButton { background-color: #10c92f; color: #ffffff; font-weight: bold; "
                                 "border-top-right-radius: 15px; "
                                 "border-top-left-radius: 0px; "
                                 "border-bottom-right-radius: 0px; "
                                 "border-bottom-left-radius: 15px; }"
                                 "QPushButton::hover { background-color: #9c0000; }");

    ui->standButton->setStyleSheet("QPushButton { background-color: #10c92f; color: #ffffff; font-weight: bold; "
                                   "border-top-right-radius: 15px; "
                                   "border-top-left-radius: 0px; "
                                   "border-bottom-right-radius: 0px; "
                                   "border-bottom-left-radius: 15px; }"
                                   "QPushButton::hover { background-color: #9c0000; }");

    ui->dealButton->setStyleSheet("QPushButton { background-color: #10c92f; color: #ffffff; font-weight: bold; "
                                  "border-top-right-radius: 15px; "
                                  "border-top-left-radius: 0px; "
                                  "border-bottom-right-radius: 0px; "
                                  "border-bottom-left-radius: 15px; }"
                                  "QPushButton::hover { background-color: #9c0000; }");

    connect(ui->decreaseBetButton, &QPushButton::clicked, [this]() { updateBetBalanceLabels(-10); });
    connect(ui->increaseBetButton, &QPushButton::clicked, [this]() { updateBetBalanceLabels(10); });
    connect(ui->coin20Button, &QPushButton::clicked, [this]() { updateBetBalanceLabels(20); });
    connect(ui->coin50Button, &QPushButton::clicked, [this]() { updateBetBalanceLabels(50); });
    connect(ui->coin100Button, &QPushButton::clicked, [this]() { updateBetBalanceLabels(100); });
    connect(ui->coin500Button, &QPushButton::clicked, [this]() { updateBetBalanceLabels(500); });
    connect(ui->coin1000Button, &QPushButton::clicked, [this]() { updateBetBalanceLabels(1000); });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateBetBalanceLabels(int value)
{
    int newBetValue = ui->betLabel->text().toInt() + value;

    if (newBetValue <= game_->getBalance() && newBetValue >= 0) {
        ui->betLabel->setText(QString::number(newBetValue));
        int currBalanceValue = ui->balanceLabel->text().toInt();
        ui->balanceLabel->setText(QString::number(currBalanceValue - value));
    }
}

void MainWindow::initGame()
{
    ui->betLabel->setText(QString::number(0));
    ui->balanceLabel->setText(QString::number(game_->getBalance()));
    ui->stackedWidget->setCurrentWidget(ui->placeBetPage);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.drawPixmap(rect(), backgroundImage_);
}


void MainWindow::on_newGameButton_clicked()
{
    this->initGame();
}


void MainWindow::on_exitButton_clicked()
{
    std::exit(0);
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
        this->initGame();
    }
}


void MainWindow::on_standButton_clicked()
{
    game_->playerStand();
    this->initGame();
}


void MainWindow::on_musicButton_clicked()
{
    ui->musicButton->setStyleSheet("image: url(:/images/icons/musicOff.svg) no-repeat; "
                                   "background-color: transparent;");

}


void MainWindow::on_volumeButton_clicked()
{
    ui->volumeButton->setStyleSheet("image: url(:/images/icons/volumeOff.svg) no-repeat; "
                                   "background-color: transparent;");
}


void MainWindow::on_exitMainMenuButton_clicked()
{

}

