#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    // 
    int n=s1.size(),m=s2.size();
    cout<<n<<" "<<m<<endl;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    //the dp table can be used to find the lcs string
    for(int i=0;i<=n;i++){for(int j=0;j<=m;j++){cout<<dp[i][j]<<" ";}cout<<endl;}
    int i=n,j=m;
    string res="";
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            res+=s1[i-1];
            i--;j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else{
            j--;
        }
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;

}

