#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

//-4%3=-1
int n,m,a,b;
vector <int> edge[100001];
int dp[100001]={0},vis[100001]={0};


int dfs(int v)
 {
    vis[v]=1;
    for(int i=0;i<edge[v].size();i++)
    {
        if(!vis[edge[v][i]])
        dfs(edge[v][i]);
        dp[v]=max(dp[v],1+dp[edge[v][i]]);
    }
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
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        dp[i]=0;
        while(m--)
        {
            cin>>a>>b;
            edge[a].push_back(b);
        }
        for(int i=1;i<=n;i++)
        if(!vis[i])
        dfs(i);
        cout<<*max_element(dp,dp+1+n);
        //for(int i=1;i<=n;i++)
        //cout<<dp[i]<<" ";
    }
}
