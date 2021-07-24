#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gameboardwindow.h"
#include "gamenetwindow.h"
#include "ui_gamenetwindow.h"
#include "gamevscomputer.h"
#include "ui_gamevscomputer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(850,640);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *){
    QPalette background;
//  background.setBrush(QPalette::Background, QBrush(QPixmap(":/images/background.jpg")));
    this->setPalette(background);
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

void MainWindow::on_pushButton_3_clicked()
{
    this->close();
    GameVsComputer* GW=new GameVsComputer;
    GW->show();
}
