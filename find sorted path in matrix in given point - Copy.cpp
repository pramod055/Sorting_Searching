#include <stdio.h>
#include <string.h>
#include<iostream>
#include <stdbool.h>
using namespace std;

#define ROW 5
#define COL 5

int v[5][5];
int ma=1000;
void dfs(int m[][5],int i,int j,int p,int q,int k)
{
    //cout<<"hi";
    if(i<0 || j<0 || i>=5 || j>=5)
       return ;
    if(i==p && j==q)
    {
           if(ma>k)
              ma=k;
           v[i][j]=0;
            return ;
    }
    if(m[i][j]==1  && v[i][j]==0)
    {
        v[i][j]=1;
        //cout<<"123";
        k=k+1;
        dfs(m,i,j-1,p,q,k);
        dfs(m,i,j+1,p,q,k);
        dfs(m,i-1,j,p,q,k);
        dfs(m,i+1,j,p,q,k);
        v[i][j]=0;
        return ;
    }
    return;
}

int main()
{
    int m[][COL]= {
        {1, 1, 0, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1}
    };
   memset(v,0,sizeof(v));
    dfs(m,1,4,2,0,0);
    printf("Distance %d\n:", ma);

    return 0;
}
