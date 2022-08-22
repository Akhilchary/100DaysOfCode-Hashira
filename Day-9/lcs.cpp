#include<bits/stdc++.h>
using namespace std;
//longest common subsequence
int lcs(int i,int j,string s1,string s2,vector<vector<int>> dp)
{
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]) 
    {
        return dp[i][j]=1+lcs(i-1,j-1,s1,s2,dp);
    }

    return dp[i][j]=max(lcs(i-1,j,s1,s2,dp),lcs(i,j-1,s1,s2,dp));
}


int memoization(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return lcs(n-1,m-1,s1,s2,dp);
}

int tabulation(string s1,string s2)
{
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    //here the index is shifted by 1
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
    for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<dp[i][j]<<" ";}cout<<endl;}
    return dp[n][m];
}

int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    cout<<memoization(s1,s2)<<" memoization"<<endl;
    cout<<tabulation(s1,s2)<<" tabulation "<<endl;
}