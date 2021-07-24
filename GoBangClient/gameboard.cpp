#include "gameboard.h"
#include <memory.h>

GameBoard::GameBoard()
{
    memset(chess,0,sizeof(chess));
    player=0;

    //清空棋盘
}
bool GameBoard::judgeOut(int x,int y)
{
    if(!chess[x][y])//判断是否在棋盘之外
        return true;
    else
        return false;
}
void GameBoard::playerPutDown(int x,int y)
{
    chess[x][y]=player++%2+4;//0空4黑5白
    chessList.push_back(QPoint(x,y));//记录下子的序列
}

bool GameBoard::WinOrNot(int x, int y)
{
    bool result = false;

    result |= check82(x,y);

    result |= check64(x,y);

    result |= check37(x,y);

    result |= check19(x,y);
    //四方向存在五子，则可断定胜利
    return result;

}
void GameBoard::backChess()
{
    if(chessList.size()==0){
     //QMessageBox::about(this,QStringLiteral("恭喜"),QStringLiteral("白棋获胜"));
     return;

    }
    int x,y;
    for(int i=0;i<1;i++)//可调节悔棋布局
    {

        x=chessList.last().x();
        y=chessList.last().y();
        chess[x][y]=0;
        player--;
        chessList.pop_back();

    }
}
void GameBoard::newGame()
{
    player=0;
    memset(chess,0,sizeof(chess));
    chessList.clear();//重新开局
}


bool GameBoard::check82(int x,int y)
{

    int i,count=0;
    for(i=1;i<5;i++)
    {
        if(y-i>=0&&chess[x][y]==chess[x][y-i])
            count++;
        else break;
    }
    for(i=1;i<5;i++)
    {
        if(y+i<=14&&chess[x][y]==chess[x][y+i])
            count++;
        else break;
    }
    if(count>=4)
        return true;
    else
        return false;
}
bool GameBoard::check64(int x,int y)
{

    int i,count=0;
    for(i=1;i<5;i++)
    {
        if(x-i>=0&&chess[x][y]==chess[x-i][y])
            count++;
        else break;
    }
    for(i=1;i<5;i++)
    {
        if(x+i<=14&&chess[x][y]==chess[x+i][y])
            count++;
        else break;
    }
    if(count>=4)
        return true;
    else
        return false;
}
bool GameBoard::check37(int x,int y)
{

    int i,count=0;
    for(i=1;i<5;i++)
    {
        if(x-i>=0&&y-i>=0&&chess[x][y]==chess[x-i][y-i])
            count++;
        else break;
    }
    for(i=1;i<5;i++)
    {
        if(y+i<=14&&x+i<=14&&chess[x][y]==chess[x+i][y+i])
            count++;
        else break;
    }
    if(count>=4)
        return true;
    else
        return false;
}
bool GameBoard::check19(int x,int y)
{

    int i,count=0;
    for(i=1;i<5;i++)
    {
        if(x+i<=14&&y-i>=0&&chess[x][y]==chess[x+i][y-i])
            count++;
        else break;
    }
    for(i=1;i<5;i++)
    {
        if(y+i<=14&&x-i>=0&&chess[x][y]==chess[x-i][y+i])
            count++;
        else break;
    }
    if(count>=4)
        return true;
    else
        return false;
}

