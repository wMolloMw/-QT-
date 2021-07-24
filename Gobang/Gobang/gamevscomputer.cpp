#include "gamevscomputer.h"
#include "ui_gamevscomputer.h"
#include "mainwindow.h"

GameVsComputer::GameVsComputer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameVsComputer),gameBoard()
{
    ui->setupUi(this);
    mouseflag=true;
    chessSkin=0;
    this->setFixedSize(850,660);
    this->setAutoFillBackground(true);
    QPalette palette;
    //调节窗口背景颜色
    //palette.setColor(QPalette::Background,QColor("#B1723C"));
    palette.setColor(QPalette::Background,QColor("#F0F8FF"));
    this->setPalette(palette);
    centralWidget()->setMouseTracking(true);
    setMouseTracking(true);
    //初始化示意棋子图片
    blackChess= new QPixmap(":/images/black.png");
    whiteChess= new QPixmap(":/images/white.png");



}

GameVsComputer::~GameVsComputer()
{
    delete blackChess;
    delete whiteChess;
    delete ui;
}

void GameVsComputer::paintEvent(QPaintEvent *)
{
    QPixmap blackChessPic(QString(":/images/black.png"));
    QPixmap whiteChessPic(QString(":/images/white.png"));
    QPixmap blackChessPic1(QString(":/images/black1.png"));
    QPixmap whiteChessPic1(QString(":/images/white1.png"));
    QPixmap blackChessPic2(QString(":/images/black2.png"));
    QPixmap whiteChessPic2(QString(":/images/white2.png"));
    QPixmap backgroundPic_chineseStyle(QString(":/images/background-chineseStyle.jpg"));//
    QPixmap backgroundPic_clouds(QString(":/images/background-clouds.jpg"));//
    QPixmap backgroundPic_sunset(QString(":/images/background-sunset.jpg"));//
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    QPen pen=painter.pen();
    //调节棋盘边缘颜色
    //pen.setColor(QColor("#8D5822"));
    pen.setColor(QColor("#483D8B"));
    pen.setWidth(7);
    painter.setPen(pen);
    QBrush brush;
    //设置棋盘背景
    switch(backgroundSkin){
    case 0 :
        brush.setColor(QColor("#EEC085"));
        brush.setColor(QColor("#B0C4DE"));
        brush.setStyle(Qt::SolidPattern);
        painter.setBrush(brush);
        //从20,40处绘制整个600X600大小的棋盘
        painter.drawRect(20,40,600,600);
        break;
    case 1:
        painter.drawPixmap(20,40,600,600,backgroundPic_chineseStyle);
        break;
    case 2:
        painter.drawPixmap(20,40,600,600,backgroundPic_clouds);
        break;
    case 3:
        painter.drawPixmap(20,40,600,600,backgroundPic_sunset);
        break;
    }
    /*
    //调节棋盘颜色
    //brush.setColor(QColor("#EEC085"));
    brush.setColor(QColor("#B0C4DE"));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    //从20,40处绘制整个600X600大小的棋盘
    painter.drawRect(20,40,600,600);
    */
    pen.setColor(Qt::black);
    pen.setWidth(1);
    painter.setPen(pen);
    for(int i=0;i<15;i++)
        {
            painter.drawLine(40+i*40,60,40+i*40,620);//纵线
            painter.drawLine(40,60+i*40,600,60+i*40);//横线
        }
    brush.setColor(Qt::black);
    //画出棋盘的四个黑点
    painter.setBrush(brush);
    painter.drawRect(155,175,10,10);
    painter.drawRect(475,175,10,10);
    painter.drawRect(155,495,10,10);
    painter.drawRect(475,495,10,10);
    painter.drawRect(315,335,10,10);
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            {
                if (gameBoard.chess[i][j] == 4)
                {
                    brush.setColor(Qt::black);
                    painter.setBrush(brush);
                    //painter.drawEllipse(QPoint((j + 1) * 40,(i + 1) * 40+20),  18, 18);
                    //修改为自定义资源图片黑棋
                    if(chessSkin==0){
                        painter.drawPixmap((j + 1) * 40 - chessSize/2,(i + 1) * 40+20 - chessSize/2,
                                          chessSize, chessSize, blackChessPic);
                    }
                    else if(chessSkin==1){
                        painter.drawPixmap((j + 1) * 40 - chessSize/2,(i + 1) * 40+20 - chessSize/2,
                                          chessSize, chessSize, blackChessPic1);
                    }
                    else{
                        painter.drawPixmap((j + 1) * 40 - chessSize/2,(i + 1) * 40+20 - chessSize/2,
                                          chessSize, chessSize, blackChessPic2);
                    }

                }
                else if (gameBoard.chess[i][j] == 5)
                {
                    brush.setColor(Qt::white);
                    painter.setPen(Qt::NoPen);
                    painter.setBrush(brush);
                    //painter.drawEllipse(QPoint((j + 1) * 40,(i + 1) * 40+20),  18, 18);
                    //修改为自定义资源图片白棋
                    if(chessSkin==0){
                        painter.drawPixmap((j + 1) * 40 - chessSize/2,(i + 1) * 40+20 - chessSize/2,
                                          chessSize, chessSize, whiteChessPic);
                    }
                    else if(chessSkin==1){
                        painter.drawPixmap((j + 1) * 40 - chessSize/2,(i + 1) * 40+20 - chessSize/2,
                                          chessSize, chessSize, whiteChessPic1);
                    }
                    else{
                        painter.drawPixmap((j + 1) * 40 - chessSize/2,(i + 1) * 40+20 - chessSize/2,
                                          chessSize, chessSize, whiteChessPic2);
                    }

                }
            }


    //pen.setColor(Qt::red);
    pen.setColor(QColor("#483D8B"));
    pen.setWidth(1);
    painter.setPen(pen);
    //当前鼠标下棋光标
    //if((moveX*40+40)>=20&&(moveX*40+40)<=620&&(moveY*40+20)>=40&&(moveY*40+20)<=640)
    //if中的条件用以校准鼠标下棋光标边缘位置
    /*
    if((moveX*40+40)>=0&&(moveX*40+40)<=600&&(moveY*40+20)>=20&&(moveY*40+20)<=600)
    {
        painter.drawLine((moveY+1)*40-20,(moveX+1)*40,(moveY+1)*40-10,(moveX+1)*40);
        painter.drawLine((moveY+1)*40+20,(moveX+1)*40,(moveY+1)*40+10,(moveX+1)*40);
        painter.drawLine((moveY+1)*40-20,(moveX+1)*40+40,(moveY+1)*40-10,(moveX+1)*40+40);
        painter.drawLine((moveY+1)*40+20,(moveX+1)*40+40,(moveY+1)*40+10,(moveX+1)*40+40);
        painter.drawLine((moveY+1)*40-20,(moveX+1)*40,(moveY+1)*40-20,(moveX+1)*40+10);
        painter.drawLine((moveY+1)*40+20,(moveX+1)*40,(moveY+1)*40+20,(moveX+1)*40+10);
        painter.drawLine((moveY+1)*40-20,(moveX+1)*40+40,(moveY+1)*40-20,(moveX+1)*40+30);
        painter.drawLine((moveY+1)*40+20,(moveX+1)*40+40,(moveY+1)*40+20,(moveX+1)*40+30);
    }
    */
    //最新下棋位置十字光标
    //替换为半透明示意棋子
    if((moveX*40+40)>=0&&(moveX*40+40)<=600&&(moveY*40+20)>=20&&(moveY*40+20)<=600){
        if(gameBoard.chess[moveX][moveY]==0){
            if((gameBoard.player)%2==0){

                painter.setOpacity(0.6);
                painter.drawPixmap((moveY+1)*40-chessSize/2,(moveX+1)*40+20-chessSize/2,
                                   chessSize,chessSize,*blackChess);
                painter.setOpacity(1.0);

            }
            else{
                painter.setOpacity(0.6);
                painter.drawPixmap((moveY+1)*40-chessSize/2,(moveX+1)*40+20-chessSize/2,
                                   chessSize,chessSize,*whiteChess);
                painter.setOpacity(1.0);
            }

        }



    }


    //切换为显眼的颜色表示新子
    pen.setColor(QColor("#00BFFF"));
    pen.setWidth(1);
    painter.setPen(pen);
    /*
    if(gameBoard.chess[currentX][currentY] == 4)
    {
      //QPen pen=painter.pen();
      pen.setColor(QColor("#00BFFF"));
      pen.setWidth(1);
      painter.setPen(pen);
    }
    *///sogou报错？？


    painter.drawLine((currentY+1)*40-1,(currentX+1)*40+20,(currentY+1)*40-6,(currentX+1)*40+20);
    painter.drawLine((currentY+1)*40+1,(currentX+1)*40+20,(currentY+1)*40+6,(currentX+1)*40+20);
    painter.drawLine((currentY+1)*40,(currentX+1)*40+19,(currentY+1)*40,(currentX+1)*40+14);
    painter.drawLine((currentY+1)*40,(currentX+1)*40+21,(currentY+1)*40,(currentX+1)*40+26);
}

void GameVsComputer::mouseReleaseEvent(QMouseEvent* event)
{
    //鼠标释放事件
    int x,y;
    if(mouseflag)
    {
        x=(event->y()-40)/40;
        y=(event->x()-20)/40;
        if(event->x()>=20&&event->x()<=620&&event->y()>=40&&event->y()<=640)
        {
            if(gameBoard.judgeOut(x,y))
            {
                gameBoard.playerPutDown(x,y);

                currentX=x;
                currentY=y;
                update();
                if(gameBoard.WinOrNot(x,y))
                {
                    if((gameBoard.player-1)%2)
                        QMessageBox::about(this,QStringLiteral("游戏结果"),QStringLiteral("白棋获胜"));
                    else
                        QMessageBox::about(this,QStringLiteral("游戏结果"),QStringLiteral("黑棋获胜"));

                    mouseflag=false;
                }
                QPoint point=gameBoard.computerPutdown();
                currentX=point.x();
                currentY=point.y();
                update();
                mouseflag=true;
                if(gameBoard.WinOrNot(currentX,currentY))
                {
                    if((gameBoard.player-1)%2)
                        QMessageBox::about(this,QStringLiteral("恭喜"),QStringLiteral("白棋获胜"));
                    else
                        QMessageBox::about(this,QStringLiteral("恭喜"),QStringLiteral("黑棋获胜"));
                    mouseflag=false;
                }
            }

        }

        update();
    }
}

void GameVsComputer::mouseMoveEvent(QMouseEvent *event)
{
    //mouseflag兼顾判断游戏是否开始的情况
    //鼠标移动事件
    if(mouseflag){
        moveX=(event->y()-40)/40;
        moveY=(event->x()-20)/40;
        update();
    }


}




void GameVsComputer::on_pushButton_clicked()
{
    //开始游戏的槽函数：功能为清除当前棋局，并开启鼠标光标显示
    gameBoard.newGame();
    currentX=0;
    currentY=0;
    mouseflag=true;
    update();
}

void GameVsComputer::on_pushButton_2_clicked()
{
    //悔棋槽函数，mouseflag兼顾判断游戏是否开始的情况
    if(mouseflag){
        gameBoard.backChess();
        update();
    }


}

void GameVsComputer::on_changeChessSkin_clicked()
{

    chessSkin=(chessSkin+1)%3;
    delete whiteChess;
    delete blackChess;
    whiteChess=NULL;
    blackChess=NULL;
    //根据皮肤切换示意棋子图片
    if(chessSkin==0){

        blackChess= new QPixmap(":/images/black.png");
        whiteChess= new QPixmap(":/images/white.png");

    }
    else if(chessSkin==1){
        blackChess= new QPixmap(":/images/black1.png");
        whiteChess= new QPixmap(":/images/white1.png");
    }
    else{
        blackChess= new QPixmap(":/images/black2.png");
        whiteChess= new QPixmap(":/images/white2.png");
    }
    update();
}


void GameVsComputer::on_pushButton_3_clicked()
{
    this->close();
    MainWindow* GW=new MainWindow;
    GW->show();
}

void GameVsComputer::on_pushButton_4_clicked()
{
    backgroundSkin=(backgroundSkin+1)%4;
    repaint();
}

