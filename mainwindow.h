#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_btnField_0_clicked();

    void on_btnField_1_clicked();

    void on_btnField_2_clicked();

    void on_btnField_3_clicked();

    void on_btnField_4_clicked();

    void on_btnField_5_clicked();

    void on_btnField_6_clicked();

    void on_btnField_7_clicked();

    void on_btnField_8_clicked();

    void clear_board();

    void play_again(char winner);

    void game_play();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
