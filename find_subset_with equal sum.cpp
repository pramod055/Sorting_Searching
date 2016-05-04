#include<iostream>
#include<stdlib.h>
using namespace std;


void sets(int a[],int i ,int sum ,int t,int n)
{
    sum-=a[i];
    t=t+a[i];
    if(sum==t)
    {
        cout<<"YES:"<<sum;
        exit(0);
    }
    for(int k=i+1;k<n;k++)
       sets(a,k,sum,t,n);
}

int main()
{
    int a[100],i,j,n,t,sum=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    for(i=0;i<n;i++)
        sets(a,i,sum,0,n);
}
