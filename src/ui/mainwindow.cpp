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
        game = std::make_unique<BlackjackGame>(1000);
    }

    ui->stackedWidget->setCurrentWidget(ui->placeBetPage);
}


void MainWindow::on_exitButton_clicked()
{
    std::exit(0);
}

