#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gameboardwindow.h"
#include "gamenetwindow.h"
#include "ui_gamenetwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->close();
    GameBoardWindow* GW=new GameBoardWindow;
    GW->show();

}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
    GameNetWindow* GW=new GameNetWindow;
    GW->show();
}
