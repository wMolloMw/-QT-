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
typedef struct
{
  int x,y,l,r;
}value;
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
    QPoint computerPutdown();
    QPoint getPoint(int index);//获取最后几条记录
    void clearChess();//清空棋盘
    int copyChess(int a[15][15]);
    void backChess();//悔棋
    void newGame();//开新局
    void setFiveValue();//生成AI权重分析逻辑图
    int chart(int count);//AI权重具体赋值
    void getSiteValue();//获取最终AI策略图
    int computerColor;
    int length;//下棋记录长度
private:
    QVector<QPoint> chessList;//下棋序列数组用于悔棋
    value fiveValue[15][15];//AI权重分析逻辑图
    int siteValue[15][15];//最终AI策略图
};

#endif // GAME_H
