#include<bits/stdc++.h>
using namespace std;

int n,vis[1000][1000];
vector <pair <int,int> > path;
int row[] = {-1, 0, 0, 1};
int col[] = { 0, 1, -1, 0};


bool safe(pair <int,int> p)
{
    return p.first>=0&&p.first<n&&p.second>=0&&p.second<n&&(!vis[p.first][p.second]);
}

int fun(pair <int,int> cur, int maze[][9])
{
    if(cur.first==n/2&&cur.second==n/2)
    {
        for(int i=0;i<path.size()-1;i++)
            cout<<path[i].first<<" "<<path[i].second<<" --> ";
        cout<<"MID";
        cout<<"\n\n";
        return 1;
    }
    int x=cur.first,y=cur.second;
    bool res=false;
    for(int i=0;i<4;i++)
    {
        int val=maze[x][y];
        int new_x=x+row[i]*val;
        int new_y=y+col[i]*val;

        pair <int,int> new_c=make_pair(new_x,new_y);
        if(safe(new_c))
        {
            vis[new_x][new_y]=1;
            path.push_back(new_c);
            res=fun(new_c,maze)||res;
            path.pop_back();
            vis[new_x][new_y]=0;
        }
    }
    return res;
}
int main()
{
    n=9;
    int maze[9][9]={
        { 3, 5, 4, 4, 7, 3, 4, 6, 3 },
        { 6, 7, 5, 6, 6, 2, 6, 6, 2 },
        { 3, 3, 4, 3, 2, 5, 4, 7, 2 },
        { 6, 5, 5, 1, 2, 3, 6, 5, 6 },
        { 3, 3, 4, 3, 0, 1, 4, 3, 4 },
        { 3, 5, 4, 3, 2, 2, 3, 3, 5 },
        { 3, 5, 4, 3, 2, 6, 4, 4, 3 },
        { 3, 5, 1, 3, 7, 5, 3, 6, 4 },
        { 6, 2, 4, 3, 4, 5, 4, 5, 1 }
    };
    int _row[] = { 0, 0, n-1, n-1};
    int _col[] = { 0, n-1, 0, n-1};
    for (int i = 0; i < 4; ++i)
    {
        int x1 = _row[i];
        int y1 = _col[i];
        cout<<"Starting coordinates are "<<x1<<" "<<y1<<"\n";

        pair<int, int> pt = make_pair(x1, y1);
        vis[x1][y1]=1;
        path.push_back(pt);
        if(!fun(pt,maze))
            cout<<"NO solution\n\n";
        path.pop_back();
        vis[x1][y1]=0;
    }

}
