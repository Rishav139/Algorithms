//CPP program for unbounded knapsack with minimization
#include<bits/stdc++.h>
using namespace std;
#define MX 10000

//returns min value of knapsack with capacity w
void unboundedKnapsack_min(int w,int val[],int wt[],int n)
{
    int dp[w+1],i,k;

    //storing maximum value
    for(i = 1; i < w + 1; i++)
        dp[i] = MX;

    dp[0] = 0;
    for(i = 1; i <= w; i++)
    {
        for(k = 0; k < n; k++)
        {
            if(wt[k] <= i)
            {
                dp[i] = min( dp[i], dp[i-wt[k]]+val[k] );
            }
        }
    }
    if(dp[w] == MX)
        cout<<"-1\n";
    else
        cout<<dp[w];
}
//Driver program
int main()
{
    int W = 5;
    int n = 2;
    int wt[] = {3 , 4};
    int val[] = {10, 30};
    unboundedKnapsack_min(W,val,wt,n);

}
