#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>
#include <QMessageBox>
#include <QString>
#include <QDir>
#include <QFileInfo>
#include <array>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int clicks_counter = 0;
std::array<char, 9> game_board;

bool check_result(std::array<char, 9> game_board){
    if ((game_board[0] == game_board[1] & game_board[1] == game_board[2] & game_board[0] != 0) ||
        (game_board[3] == game_board[4] & game_board[4] == game_board[5] & game_board[3] != 0) ||
        (game_board[6] == game_board[7] & game_board[7] == game_board[8] & game_board[6] != 0) ||
        (game_board[0] == game_board[3] & game_board[3] == game_board[6] & game_board[0] != 0) ||
        (game_board[1] == game_board[4] & game_board[4] == game_board[7] & game_board[1] != 0) ||
        (game_board[2] == game_board[5] & game_board[5] == game_board[8] & game_board[2] != 0) ||
        (game_board[0] == game_board[4] & game_board[4] == game_board[8] & game_board[4] != 0) ||
        (game_board[2] == game_board[4] & game_board[4] == game_board[6] & game_board[4] != 0)){
        return 1;
    }
    return 0;
}

char check_winner(int clicks){
    if (check_result(game_board)){
        if (clicks % 2 == 0){
            return 'x';
        }
        else{
            return 'o';
        }
    }

    if (clicks == 8){
        return 't';
    }

    return 0;
}

void MainWindow::clear_board(){
    ui->btnField_0->setIcon(QIcon());
    ui->btnField_1->setIcon(QIcon());
    ui->btnField_2->setIcon(QIcon());
    ui->btnField_3->setIcon(QIcon());
    ui->btnField_4->setIcon(QIcon());
    ui->btnField_5->setIcon(QIcon());
    ui->btnField_6->setIcon(QIcon());
    ui->btnField_7->setIcon(QIcon());
    ui->btnField_8->setIcon(QIcon());

    ui->btnField_0->setEnabled(true);
    ui->btnField_1->setEnabled(true);
    ui->btnField_2->setEnabled(true);
    ui->btnField_3->setEnabled(true);
    ui->btnField_4->setEnabled(true);
    ui->btnField_5->setEnabled(true);
    ui->btnField_6->setEnabled(true);
    ui->btnField_7->setEnabled(true);
    ui->btnField_8->setEnabled(true);

    game_board.fill(0);
    clicks_counter = -1;
}

QString final_msg(char winner){
    if (winner == 'x'){
        return "X wins! Do you want to play again?";
    }
    else if (winner == 'o'){
        return "O wins! Do you want to play again?";
    }
    else{
        return "It's a tie! Do you want to play again?";
    }
}


void MainWindow::play_again(char winner){
        if (QMessageBox::information(this, "Restart?", final_msg(winner), QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes){
            clear_board();
        }
        else{
            QApplication::quit();
        }
}

void MainWindow::game_play(){
    char result = check_winner(clicks_counter);

    if (result != 0){
        play_again(result);
    }
    clicks_counter ++;
}

void MainWindow::on_btnField_0_clicked()
{
    if (clicks_counter % 2 == 0){
        ui->btnField_0->setIcon(QIcon(":/x.png"));
        game_board[0] = 'X';
    }
    else{
        ui->btnField_0->setIcon(QIcon(":/o.png"));
        game_board[0] = 'O';
    }

    ui->btnField_0->setDisabled(true);

    game_play();
}


void MainWindow::on_btnField_1_clicked()
{
    if (clicks_counter % 2 == 0){
        ui->btnField_1->setIcon(QIcon(":/x.png"));
        game_board[1] = 'X';
    }
    else{
        ui->btnField_1->setIcon(QIcon(":/o.png"));
        game_board[1] = 'O';
    }

    ui->btnField_1->setDisabled(true);

    game_play();
}


void MainWindow::on_btnField_2_clicked()
{
    if (clicks_counter % 2 == 0){
        ui->btnField_2->setIcon(QIcon(":/x.png"));
        game_board[2] = 'X';
    }
    else{
        ui->btnField_2->setIcon(QIcon(":/o.png"));
        game_board[2] = 'O';
    }

    ui->btnField_2->setDisabled(true);

    game_play();
}


void MainWindow::on_btnField_3_clicked()
{
    if (clicks_counter % 2 == 0){
        ui->btnField_3->setIcon(QIcon(":/x.png"));
        game_board[3] = 'X';
    }
    else{
        ui->btnField_3->setIcon(QIcon(":/o.png"));
        game_board[3] = 'O';
    }

    ui->btnField_3->setDisabled(true);

    game_play();
}


void MainWindow::on_btnField_4_clicked()
{
    if (clicks_counter % 2 == 0){
        ui->btnField_4->setIcon(QIcon(":/x.png"));
        game_board[4] = 'X';
    }
    else{
        ui->btnField_4->setIcon(QIcon(":/o.png"));
        game_board[4] = 'O';
    }

    ui->btnField_4->setDisabled(true);

    game_play();
}


void MainWindow::on_btnField_5_clicked()
{
    if (clicks_counter % 2 == 0){
        ui->btnField_5->setIcon(QIcon(":/x.png"));
        game_board[5] = 'X';
    }
    else{
        ui->btnField_5->setIcon(QIcon(":/o.png"));
        game_board[5] = 'O';
    }

    ui->btnField_5->setDisabled(true);

    game_play();
}


void MainWindow::on_btnField_6_clicked()
{
    if (clicks_counter % 2 == 0){
        ui->btnField_6->setIcon(QIcon(":/x.png"));
        game_board[6] = 'X';
    }
    else{
        ui->btnField_6->setIcon(QIcon(":/o.png"));
        game_board[6] = 'O';
    }

    ui->btnField_6->setDisabled(true);

    game_play();
}


void MainWindow::on_btnField_7_clicked()
{
    if (clicks_counter % 2 == 0){
        ui->btnField_7->setIcon(QIcon(":/x.png"));
        game_board[7] = 'X';
    }
    else{
        ui->btnField_7->setIcon(QIcon(":/o.png"));
        game_board[7] = 'O';
    }

    ui->btnField_7->setDisabled(true);

    game_play();
}


void MainWindow::on_btnField_8_clicked()
{
    if (clicks_counter % 2 == 0){
        ui->btnField_8->setIcon(QIcon(":/x.png"));
        game_board[8] = 'X';
    }
    else{
        ui->btnField_8->setIcon(QIcon(":/o.png"));
        game_board[8] = 'O';
    }

    ui->btnField_8->setDisabled(true);

    game_play();
}

