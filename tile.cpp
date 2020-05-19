#include<bits/stdc++.h>
using namespace std;

int sze,b,a,cnt=0;
int arr[128][128];

void put(int x1,int y1,int x2,int y2,int x3, int y3)
{
	cnt++;
	arr[x1][y1] = cnt;
	arr[x2][y2] = cnt;
	arr[x3][y3] = cnt;
}

int tile(int n,int x,int y)
{
    int hr,hc;
    if(n==2)
    {
        cnt++;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(arr[x+i][y+j]==0)
                arr[x+i][y+j]=cnt;
        return 0;
    }
    for(int i=x;i<n;i++)      //finding hole location
        for(int j=y;j<n;j++)
            if(arr[i][j]!=0)
            hr=i, hc=j;

    if(hr< x + n/2 &&hc < y+ n/2)
		put(x+n/2,y+ (n/2) - 1,x+n/2,y+n/2,x+n/2-1,y+n/2);

	//If missing Tile is in 2st quadrant
	else if(hr>=x+ n/2 && hc < y + n/2)
		put(x+n/2,y+ (n/2) - 1,x+n/2,y+n/2,x+n/2-1,y+n/2-1);

	//If missing Tile is in 3st quadrant
	else if(hr < x + n/2 && hc >= y + n/2)
		put(x+(n/2) - 1,y+ (n/2),x+(n/2),y+n/2,x+(n/2)-1,y+(n/2) -1);

	//If missing Tile is in 4st quadrant
	else if(hr >= x + n/2 && hc >= y + n/2)
		put(x+(n/2) -1, y+ (n/2),x+(n/2),y+(n/2) -1,x+(n/2)-1,y+(n/2)-1);

    tile(n/2, x, y+n/2);
	tile(n/2, x, y);
	tile(n/2, x+n/2, y);
	tile(n/2, x+n/2, y+n/2);

    return 0;
}

int main()
{
    cout<<"Enter size of box\n";
    cin>>sze;
    memset(arr,0,sizeof(arr));
    cout<<"Enter coordinates which you want to be marked\n";
    cin>>a>>b;
    arr[a][b]=-1;

    tile(sze,0,0);
    cout<<"\nThe grid is \n";
    for(int i=0;i<sze;i++)
    {
        for(int j=0;j<sze;j++)
            cout<<arr[i][j]<<" \t";
        cout<<"\n";
    }
}
