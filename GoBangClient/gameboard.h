#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QVector>
#include <QPoint>
#include <QMessageBox>
#include <QFileDialog>
#include <QPainter>
#include <QMainWindow>
#include <QMouseEvent>
#include <QPixmap>

class GameBoard//棋盘类
{
public:
    GameBoard();
    int chess[15][15];//棋盘信息0空4黑5白
    int player;//包括步长与当前下棋者的信息
    bool check82(int x,int y);//检查纵向
    bool check64(int x,int y);//检查横向
    bool check37(int x,int y);//检查左斜
    bool check19(int x,int y);//检查右斜
    bool judgeOut(int x,int y);//判断鼠标的位置是否
    bool WinOrNot(int x,int y);//结合起来就是判断胜利函数
    void playerPutDown(int x,int y);//人下棋
    void backChess();//悔棋
    void newGame();//开新局
private:
    QVector<QPoint> chessList;//下棋序列数组用于悔棋
};

#endif // GAME_H
