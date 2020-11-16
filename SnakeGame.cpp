#include <iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
bool gameOver ;
const int width=40 ,height=20;
int x,y,fruitX,fruitY,score;
int tailX[1000], tailY[1000];
int nTail;
enum eDirection {STOP = 0, LEFT , RIGHT , UP , DOWN };
eDirection dir;

void setup()
{
    gameOver = false ;
    dir = STOP;
    x = width/2;
    y = height/2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score=0;
    
}

void draw()
{

    system("cls");
    cout<<"---------------SNAKE GAME---------------"<<endl;
    for(int i = 0; i < width+2; i++)
    {
        cout<<"#";
    }
    cout<<endl ;
    for(int i=0 ; i < height; i++)
    {
        for(int j=0; j<width;j++)
        {
            if(j==0)
            {
                cout<<"#";
            }
            if (i==y && j==x)
            {
                cout<<"O";
            }

            else if (i==fruitY && j==fruitX)
            {
                cout<<"*";
            } 

            else
            {
                bool print=false;
                for(int k=0; k<nTail; k++)
                {
                    if(tailX[k] == j && tailY[k] == i)
                    {
                        cout<<"o";
                        print = true;
                    }
                }
                if(!print)
                {
                    cout<<" ";
                }
            }
            if(j==width-1)
            {
                cout<<"#";
            }
        }
        cout<<endl ;
    }
    cout<<endl ;

    for(int i = 0; i < width+2; i++)
    {
        cout<<"#";
    }

    cout<<endl ;

    cout<<"score = "<<score<<endl;
}

void input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
            case 'a' :
            {
                dir = LEFT;
                break;
            }
            case 'w' :
            {
                dir = UP;
                break;
            }
            case 'd' :
            {
                dir = RIGHT;
                break ;
            }
            case 's' :
            {
                dir = DOWN ;
                break ;
            }

            case 'x' :
            {
                gameOver = true ;
                break;
            }

        }
    }
}

void logic()
{
    int privX = tailX[0];
    int privY = tailY[0];
    int priv2X , priv2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i=1; i<nTail; i++)
    {
        priv2X = tailX[i];
        priv2Y = tailY[i];
        tailX[i] = privX;
        tailY[i] = privY;
        privX = priv2X;
        privY = priv2Y;
    }
    switch(dir)
    {
        case LEFT :
        {
            x--;
            break;
        }
        case RIGHT :
        {
            x++;
            break;
        }
        case UP :
        {
            y--;
            break;
        }
        case DOWN :
        {
            y++;
            break;
        }
        default :
        {
            break;
        }
    }

    if(x < 0)
    {
        x = width-1;
    }
    else if(x > width)
    {
        x = 0;
    }

    if(y < 0)
    {
        y = width-1;
    }
    else if(y > width)
    {
        y = 0;
    }


    for (int i=0; i<nTail; i++)
    {
        if(tailX[i]==x && tailY[i]==y)
        {
            gameOver=true;
        }
    }

    if(x==fruitX && y==fruitY)
    {
        score+=10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

int main ()
{   setup();
    
    while (!gameOver)
    {
        draw();
        input();
        logic();
        Sleep(15);
    }
}