#include<bits/stdc++.h>
using namespace std;

int x=INT_MIN,m,p;
int fun(int n,int arr[][25],int r[],int c[])
{ m=0;
    if(n==0)
        return 0;
    for(int i=0;i<n;i++)
    {
        if(r[i]==0)
        {
            for(int j=0;j<n;j++)
            {
                if(c[j]==0)
                {
                    r[i]=1;
                    c[j]=1;
                    p=fun(n-1,arr,r,c);
                    m=p+arr[i][j];
                    x=max(x,m);
                    r[i]=0;
                    c[j]=0;
                }
            }
        }
    }
    return x;
}
int main()
{
    int n,cnt=0;
    cin>>n;
    int arr[n][25],r[n]={0},c[n]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[i][j]=++cnt;
            cout<<arr[i][j]<<" \t ";
        }
        cout<<endl;
    }
    int val=fun(n,arr,r,c);
    cout<<val;
    return 0;
}
