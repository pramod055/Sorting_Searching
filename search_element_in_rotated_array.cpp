#include<iostream>
using namespace std;
int main()
{
    int ar[100],n,i,l,r,m,s,flag=-1;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>ar[i];
    l=0,r=n-1;
    cout<<"\nenter searching element\n";
    cin>>s;
    while(l<=r)
    {
        m=(l+r)/2;
        if(ar[m]==s)
        {
            flag=m;
            break;
        }
        if(ar[l]<=ar[m])
        {
            if(ar[l]<=s && s<ar[m])
                r=m-1;
            else
                l=m+1;
        }
        else
        {
            if(ar[m]<s && s<=ar[r])
                l=m+1;
            else
                r=m-1;
        }
    }

    if(flag==-1)
        cout<<"not found\n";
    else
        cout<<"found at index="<<flag;
}

