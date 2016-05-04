#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    char s[100];
    int flag=0,i,j,n,a=0,b=1,sum=0;
    gets(s);
    for(i=strlen(s)-1;i>=0;i--)
    {
        int p=s[i]-'0';
        if(p>=0 && p<=9)
        {
            if(flag==0)
            {
                a=p;
                flag=1;
            }
            else
            {
                b=b*10;
                a=a+b*p;
            }

        }
        else
        {
            if(flag==1 && s[i]!='-')
            {
                sum=sum+a;
                flag=0;b=1;
            }
            if(flag==1 && s[i]=='-')
            {
                sum=sum-a;
                flag=0;b=1;
            }
        }
    }
    if(flag==0)
    cout<<sum;
    else
        cout<<a;
}
