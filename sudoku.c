#include<stdio.h>
void printsudoku(void);
int solvesudoku(int x,int y);
int samec(int x,int y,int num);
int sames(int x,int y,int num);
int samer(int x,int y,int num);
sudoku[9][9]={5,3,0,0,7,0,0,0,0,6,0,0,1,9,5,0,0,0,0,9,8,0,0,0,0,6,0,
             8,0,0,0,6,0,0,0,3,4,0,0,8,0,3,0,0,1,7,0,0,0,2,0,0,0,6,0,6,0,0,0,0,2,8,0
             ,0,0,0,4,1,9,0,0,5,0,0,0,0,8,0,0,7,9};


int main()
{
    /*printf("enter elements of sudoku row-wise");
    int sudoku1[9][9];
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            scanf("%d",&sudoku1[i][j]);
            sudoku[i][j]=sudoku1[i][j];

        }
    }*/
    int x=0,y=0;
    printsudoku();
    solvesudoku(x,y);
    printsudoku();
    return 0;

}
void printsudoku(void)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            printf("%d  ",sudoku[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}
int samec(int x,int y,int num)
{
    for(int i=0;i<9;i++)
    {
        if(sudoku[x][i]==num)
            return 1;
    }
    return 0;
}
int samer(int x,int y,int num)
{
    for(int i=0;i<9;i++)
    {
        if(sudoku[i][y]==num)
            return 1;
    }
    return 0;
}
int sames(int x,int y,int num)
{
    if(x<3)
        x=0;
    else if(x<6)
        x=3;
    else if(x<9)
        x=6;
    if(y<3)
        y=0;
    else if(y<6)
        y=3;
    else if(y<9)
        y=6;


    for(int i=x;i<x+3;i++)
    {for(int j=y;j<y+3;j++){
        if(sudoku[i][j]==num)
            return 1;}
    }
    return 0;
}
int solvesudoku(int x,int y)
{
    int num=1,tx=0,ty=0;
    if(sudoku[x][y]!=0)
    {  if(x==8 && y==8)
    return 1;
        if(x<8)
            x++;
        else if(y<8)
        {y++;x=0;}

        if(solvesudoku(x,y))
            return 1;
        else return 0;
    }
    if(sudoku[x][y]==0)
    {
        while(num<10)
        {
            if(!samec(x,y,num) && !samer(x,y,num) && !sames(x,y,num))
            {
                sudoku[x][y]=num;
                if(x==8 && y==8)
                    return 1;
                if(x<8)
                    tx=x+1;
                else if(y<8)
                {
                    ty=y+1;
                    tx=0;
                }
                if(solvesudoku(tx,ty))
                    return 1;
            }num++;
        }
        sudoku[x][y]=0;
        return 0;
    }
}
