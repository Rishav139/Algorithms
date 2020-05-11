#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

//-4%3=-1
        lld n,w;
        lld wt[101],val[101],dp[100001][101];
lld min(lld a,lld b)
{
    if(a<b)
    return a;
    else
    return b;
}

lld fun(lld sval,lld i)
{
    if(sval<=0)
    return 0;
    if(i==n+1)
    return 1e9+1;
    if(dp[sval][i]!=-1)
    return dp[sval][i];
    else
    return dp[sval][i]=min(fun(sval,i+1),wt[i]+fun(sval-val[i],i+1));
}
int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    //cin>>t;
    t=1;
    while(t--)
    {
        lld sum=0,r,mval=INT_MAX;
        cin>>n>>w;
        for(int i=1;i<=n;i++)
        {
            cin>>wt[i]>>val[i];
            sum+=val[i];
            //mval=min(val[i],mval);
        }
        memset(dp,-1,sizeof(dp));
        for(r=sum;r>=0;r--)
        //cout<<fun(r,1)<<" "<<r<<"\n";
        if(fun(r,1)<=w)
        {
            cout<<r;
            break;
        }
    }
}

