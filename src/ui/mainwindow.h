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

private:
    void updateBetBalanceLabels(int value);
    void initGame();

protected:
    void paintEvent(QPaintEvent* event) override;

private slots:
    void on_newGameButton_clicked();

    void on_exitButton_clicked();

    void on_dealButton_clicked();

    void on_hitButton_clicked();

    void on_standButton_clicked();

    void on_musicButton_clicked();

    void on_volumeButton_clicked();

    void on_exitMainMenuButton_clicked();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<BlackjackGame> game_;
    QPixmap backgroundImage_;
};
#endif // MAINWINDOW_H
