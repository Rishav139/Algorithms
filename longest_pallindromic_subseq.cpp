#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    str="";
    cin>>str;
    int n=str.length();
    int lps[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        lps[i][j]=0;
    for(int i=0;i<n;i++)
        lps[i][i]=1;
    cout<<"For length 1"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<lps[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    for (int len=2;len<=n;len++)
    {
        for (int i=0;i<n-len+1;i++)
        {
            int j=i+len-1;
            if (str[i]==str[j]&&len==2)
               lps[i][j]=2;
            else if (str[i]==str[j])
               lps[i][j]=lps[i+1][j-1]+2;
            else
               lps[i][j] = max(lps[i][j-1],lps[i+1][j]);
        }
         cout<<"For length "<<len<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<lps[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    cout<<"Length of longest pallindromic subsequence is "<<lps[0][n-1]<<endl;
    string sl,sr;
    sl=sr="";
    int i=0,j=n-1;
    while(lps[i][j]!=0)
    {
        if(lps[i][j]!=lps[i+1][j]&&lps[i][j]!=lps[i][j-1])
        {
            if(i!=j)
            {
                sl+=str[i];
                sr+=str[j];
            }
            else
                sl+=str[i];
            i++;
            j--;
        }
        else if(lps[i][j]==lps[i+1][j]&&lps[i][j]!=lps[i][j-1])
            i++;
        else
            j--;
    }
    reverse(sr.begin(),sr.end());
    cout<<sl<<sr;
return 0;
}


