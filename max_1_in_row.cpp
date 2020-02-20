//matrix should be sorted

#include<bits/stdc++.h>
using namespace std;

int row_max(int arr[][25],int r,int c)
{
    int ptr=0,j,val=0;
    for(int i=0;i<c;i++)
        if(arr[0][i]==1)
        {
            ptr=1;
            j=i;
            break;
        }
    if(ptr==0)
        j=c-1;

    for(int i=1;i<r;i++)
    {
        while(j>=0&&arr[i][j]==1)
            {
                j--;
                val=i;
            }
    }
    return val;
}

int main()
{
    int r,c;
    cout<<"enter no of rows and columns\n";
    cin>>r>>c;
    int arr[r][25];
    cout<<"enter values\n";
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        cin>>arr[i][j];
    int res=row_max(arr,r,c);
    cout<<"Row with max 1s is "<<++res;
    return 0;
}
