#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int l,int h)
{
    int pivot=arr[h];
    int i=l-1;

    for(int j=l;j<h;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}

void quick_sort(int arr[],int l,int h)
{
    if(l<h)
    {
        int m=partition(arr,l,h);
        quick_sort(arr,l,m-1);
        quick_sort(arr,m+1,h);
    }
    return ;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    quick_sort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i];
    return 0;
}
