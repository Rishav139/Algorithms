#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int LIS[n];
    for(int i=0;i<n;i++)
    LIS[i]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
            if(arr[i]>arr[j])
                LIS[i]=max(LIS[i],LIS[j]+1);
        cout<<"At index "<<i+1<<" LIS array is ";
        for(int i=0;i<n;i++)
            cout<<LIS[i]<<" ";
        cout<<endl;
    }
    int ans= *max_element(LIS,LIS+n);
    cout<<"The longest increasing subsequence is "<<ans;
    return 0;
}
