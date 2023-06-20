#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "src/gamelogic/blackjackgame.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_newGameButton_clicked();

    void on_exitButton_clicked();

    void on_increaseBetButton_clicked();

    void on_decreaseBetButton_clicked();

    void on_dealButton_clicked();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<BlackjackGame> game;
};
#endif // MAINWINDOW_H
