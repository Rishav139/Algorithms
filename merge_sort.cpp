#include<bits/stdc++.h>
using namespace std;

int merge(int arr[],int l,int m,int h)
{
    int i,j,k;
    int l1 = m - l + 1;
    int l2 =  h - m;

    int larr[l1], rarr[l2];

    for (i = 0; i < l1; i++)
        larr[i] = arr[l + i];
    for (j = 0; j < l2; j++)
        rarr[j] = arr[m + 1+ j];

    i=0,k=l;
    j=0;

    while(i<l1&&j<l2)
    {
        if(larr[i]<rarr[j])
            arr[k++]=larr[i++];
        else
            arr[k++]=rarr[j++];
    }
    while(i<l1)
        arr[k++]=larr[i++];
    while(j<l2)
        arr[k++]=rarr[j++];
}

void merge_sort(int arr[],int l,int h)
{
    if(l<h)
    {
        int m=(l+h)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,h);
        merge(arr,l,m,h);
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i];
    return 0;
}
