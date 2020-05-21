#include<bits/stdc++.h>
using namespace std;
#define R 4
#define C 4
int cnt[R+1][C+1][100000];

int minCost(int cost[R][C], int m, int n)
{


	int tc[R][C];

	tc[0][0] = cost[0][0];

	for (int i = 1; i <= m; i++)
		tc[i][0] = tc[i-1][0] + cost[i][0];

	for (int j = 1; j <= n; j++)
		tc[0][j] = tc[0][j-1] + cost[0][j];

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			tc[i][j] = min(tc[i-1][j], tc[i][j-1]) + cost[i][j];

	return tc[m][n];
}

int count_path(int cost[R][C], int val,int m,int n)
{
    if(m<0 || n<0 || val<0)
        return 0;
    if(m==0&&n==0)
    {
        if(val==cost[0][0])
           return 1;
        else
            return 0;
    }
    if(cnt[m][n][val]==-1)
    cnt[m][n][val] = count_path(cost, val-cost[m][n], m-1, n) + count_path(cost, val-cost[m][n], m, n-1);
    return cnt[m][n][val];
}
int main()
{
   int cost[R][C] ={{4,7,8,6},
					{6,7,3,9},
					{3,8,1,2},
                    {7,1,7,3}};
   memset(cnt,-1,sizeof(cnt));
int mincost = minCost(cost,R-1,C-1);
int paths = count_path(cost,mincost,R-1,C-1);

cout<<"The no. of paths with minimum cost of "<<mincost<<" is "<<paths<<endl;
return 0;
}
