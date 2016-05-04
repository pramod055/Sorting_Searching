#include<iostream>
using namespace std;
int main()
{
     int a[]={0,0,0,0,0,0};
     int n=sizeof(a)/sizeof(a[0]);
     int flag=0,c=0,max=-1,pres=0,loc,i;
     for(i=0;i<n;i++)
     {
         if(a[i]==0 && flag==0)
         {
             pres=i;
             flag=1;
         }
         else if(a[i]==0 && flag==1)
         {
             if(c>max)
             {
                 max=c;
                 loc=pres;
            }
            c=i-pres-1;
            pres=i;
         }
         c++;
     }

     if(max<c)
     {
         max=c;
         loc=pres;
     }
     cout<<"No. of zero:"<<max<<"\nLOc of ZERo: "<<loc;
}
