#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int l,int h)
{
    int pivot=arr[h];
    int i=l;

    for(int j=l;j<h;j++)
    {
        if(arr[j]<=pivot)
        {
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[h]);
    return i;
}

int k_smallest(int arr[],int l,int h,int k)
{
    if(k>0&&k<=h-l+1)
    {
        int m=partition(arr,l,h);

        if(m-l==k-1)
            return arr[m];
        else if(m-l>k-1)
            return k_smallest(arr,l,m-1,k);
        else
            return k_smallest(arr,m+1,h,k-(m-l)-1);
    }
    return -34;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    int res=k_smallest(arr,0,n-1,k);
    cout<<res;
    return 0;
}
