#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

int v[5][5];

void dfs(int m[][5],int i,int j)
{

    if(i<0 || j<0 || i>=5 || j>=5)
       return ;
    if(m[i][j]==1 && v[i][j]!=1)
    {
        v[i][j]=1;
        dfs(m,i-1,j-1);
        dfs(m,i-1,j);
        dfs(m,i-1,j+1);
        dfs(m,i,j-1);
        dfs(m,i,j+1);
        dfs(m,i+1,j-1);
        dfs(m,i+1,j);
        dfs(m,i+1,j+1);
    }
}

int main()
{
    int m[][COL]= {
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };
   int count=0,i,j;

   memset(v,0,sizeof(v));

    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
       {
           if(m[i][j]==1 && v[i][j]==0)
           {
               count++;
               dfs(m,i,j);
           }
       }



    printf("Number of islands is: %d\n", count);

    return 0;
}
