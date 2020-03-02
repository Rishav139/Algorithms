#include<bits/stdc++.h>
using namespace std;

int cr_sum(int arr[],int l,int m,int h)
{
    int sum=0;
    int l_sum=INT_MIN,r_sum=INT_MIN;

    for(int i=m;i>=l;i--)
    {
        sum+=arr[i];
        if(sum>l_sum)
            l_sum=sum;
    }
    sum=0;
    for(int i=m+1;i<=h;i++)
    {
        sum+=arr[i];
        if(sum>r_sum)
            r_sum=sum;
    }
    return l_sum+r_sum;
}

int max_sum(int arr[],int l,int h)
{
    if(l==h)
        return arr[l];
    int m=(l+h)/2;
    return max(max_sum(arr,l,m),max(max_sum(arr,m+1,h),cr_sum(arr,l,m,h)));
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int res=max_sum(arr,0,n-1);
    cout<<res;
    return 0;
}
