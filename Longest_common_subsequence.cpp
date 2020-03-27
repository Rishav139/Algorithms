#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2;
    s1=s2="";
    cin>>s1>>s2;
    int m=s1.length();
    int n=s2.length();
    int lcs[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
                lcs[i][j]=0;
            else if(s1[i-1]==s2[j-1])
                lcs[i][j]=lcs[i-1][j-1]+1;
            else
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
        }
        cout<<"At i="<<i<<" matrix is - ";
        for(int j=0;j<=n;j++)
            cout<<lcs[i][j]<<" ";
        cout<<endl;
    }
    int len=lcs[m][n];
    char res[len+1];
    res[len]='\0';
    while(m>0&&n>0)
    {
        if(s1[m-1]==s2[n-1])
        {
            res[len-1]=s1[m-1];
            m--;
            n--;
            len--;
        }
        else if(lcs[m-1][n]>lcs[m][n-1])
            m--;
        else
            n--;
    }
    cout<<"Longest common subsequence is "<<res;

return 0;
}
