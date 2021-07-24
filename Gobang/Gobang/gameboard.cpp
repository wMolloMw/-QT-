#include "gameboard.h"
#include <memory.h>

GameBoard::GameBoard()
{
    memset(chess,0,sizeof(chess));
    player=0;
    length = 0;
    computerColor = 5;
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
    ++length;
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
void GameBoard::setFiveValue()
{
    for(int i=0;i<15;i++)
        for(int j=0;j<15;j++)
        {
            int count=0;          //x
            if(j<11)
            {
                for(int n=0;n<5;n++)
                {
                  count+=chess[i][j+n];
                }
                fiveValue[i][j].x=chart(count);
            }
            count=0;             //y
            if(i<11)
            {
                for(int n=0;n<5;n++)
                {
                  count+=chess[i+n][j];
                }
                fiveValue[i][j].y=chart(count);
            }
            count=0;             //r
            if(i<11&&j<11)
            {
                for(int n=0;n<5;n++)
                {
                  count+=chess[i+n][j+n];
                }
                fiveValue[i][j].r=chart(count);
            }
            count=0;             //l
            if(j>=4&&i<11)
            {
                for(int n=0;n<5;n++)
                {
                  count+=chess[i+n][j-n];
                }
                fiveValue[i][j].l=chart(count);
            }
        }
}
void GameBoard::getSiteValue()
{
    for(int i=0;i<15;i++)
        for(int j=0;j<15;j++)
        {
            siteValue[i][j]=fiveValue[i][j].l+fiveValue[i][j].r+fiveValue[i][j].x+fiveValue[i][j].y;
            for(int n=1;n<5;n++)
            {
                if(j-n>=0)
                    siteValue[i][j]+=fiveValue[i][j-n].x;
                if(i-n>=0)
                    siteValue[i][j]+=fiveValue[i-n][j].y;
                if(i-n>=0&&j-n>=0)
                    siteValue[i][j]+=fiveValue[i-n][j-n].r;
                if(i-n>=0&&j+n<=14)
                    siteValue[i][j]+=fiveValue[i-n][j+n].l;
            }
        }
}
int GameBoard::chart(int count)
{
    int temp;
    if(computerColor==4)
    {
        switch(count)
        {
           case 0: temp=7;break;
           case 4: temp=35;break;
           case 8: temp=800;break;
           case 12: temp=15000;break;
           case 16: temp=800000;break;
           case 5: temp=15;break;
           case 10: temp=400;break;
           case 15: temp=1800;break;
           case 20: temp=100000;break;
           default: temp=0;
        }
     }
    else if(computerColor==5)
    {
        switch(count)
        {
           case 0: temp=7;break;
           case 4: temp=15;break;
           case 8: temp=400;break;
           case 12: temp=1800;break;
           case 16: temp=100000;break;
           case 5: temp=35;break;
           case 10: temp=800;break;
           case 15: temp=15000;break;
           case 20: temp=800000;break;
           default: temp=0;
        }
    }
    return temp;
}
QPoint GameBoard::computerPutdown()
{
    int temp=0,x=0,y=0;
    setFiveValue();
    getSiteValue();
    for(int i=0;i<15;i++)
        for(int j=0;j<15;j++)
            {
                if(chess[i][j]==0)
                    if(siteValue[i][j]>=temp)
                    {
                        temp=siteValue[i][j];
                        x=i;
                        y=j;
                    }

            }

    if(player==0)
    {
        chess[7][7]=player++%2+4;
        chessList.push_back(QPoint(7,7));
        ++length;
    }
    else
    {
        chess[x][y]=player++%2+4;
        chessList.push_back(QPoint(x,y));
        ++length;
    }

    return QPoint(x,y);
}
QPoint GameBoard::getPoint(int index){
    return chessList[index];
}
void GameBoard::clearChess(){
    player=0;
    memset(chess,0,sizeof(chess));
}
int GameBoard::copyChess(int a[15][15]){
    for(int i = 0;i < 15;++i){
        for(int j = 0;j < 15;++j){
            a[i][j] = chess[i][j];
        }
    }
}
