#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
int main()
{
    string s[100];
    int n,j,i,z,k,maxl=-100;
    char ch;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>s[i];
    for(i=0;i<n;i++)
    {
        int l=s[i].length();
        if(l>maxl)
            maxl=l;
    }

    for(i=0;i<maxl;i++)
    {
        vector<string>v[10];
        for(j=0;j<n;j++)
        {
            int p=s[j].length();
            if(p-i-1>=0)
                ch=s[j].at(p-i-1);
            else
                ch='0';
            int q=ch-'0';
            v[q].push_back(s[j]);
        }
        z=0;
        //vector<string>::iterator t;
        int t;
        for(k=0;k<10;k++)
        {
            for(int t=0;t<v[k].size();t++)
            {
                s[z++]=v[k][t];
            }
        }
    }
    cout<<"...............................";
    for(i=0;i<n;i++)
        cout<<s[i]<<" ";
}


