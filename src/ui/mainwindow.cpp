#include "src/ui/mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_newGameButton_clicked()
{
    if (!game) {
        game = std::make_unique<BlackjackGame>(1000, ui->gamePage);
    }

    ui->stackedWidget->setCurrentWidget(ui->placeBetPage);
}


void MainWindow::on_exitButton_clicked()
{
    std::exit(0);
}


void MainWindow::on_increaseBetButton_clicked()
{
    int bet = ui->betLabel->text().toInt();
    if (game->getBalance() >= bet + 10) {
        ui->betLabel->setText(QString::number(bet + 10));
    }
}


void MainWindow::on_decreaseBetButton_clicked()
{
    int bet = ui->betLabel->text().toInt();
    if (0 <= bet - 10) {
        ui->betLabel->setText(QString::number(bet - 10));
    }
}


void MainWindow::on_dealButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->gamePage);
    game->start();
}

