#include<bits/stdc++.h>
using namespace std;
//longest increasing subsequence
int rec(int i,int prev,vector<int> &nums)
{
    if(i==nums.size()) return 0;
    int l=0;
    if(nums[i]>prev)
    {
        l=rec(i+1,nums[i],nums);
    }
    int r=rec(i+1,prev,nums);
    return max(l,r);
}

//1d array dp but O(n^2) solutions
int LIS(vector<int> &nums)
{
    int n=nums.size();
    vector<int> dp(n,1);
    for(int i=0;i<n;i++)
    {
        for(int prev=0;prev<i;prev++)
        {
            if(nums[prev]<nums[i])
            {
                dp[i]=max(dp[i],1+dp[prev]);
            }
        }
    }
    //lis will be max of dp which gives longest increasing subsequence that can
    //be formed at that index
    int mx=1;
    for(auto i:dp) mx=max(mx,i);
    return mx;
}
int main()
{
    vector<int> nums={5,4,11,1,16,8};
    int n=nums.size();
    // return rec(0,-1,nums);
    //tabulation
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int prev=i-1;prev>=-1;prev--)
        {
            int ntake=dp[i+1][prev+1],take=0;
            if(prev==-1 || nums[i]>nums[prev])
            {
                take=1+dp[i+1][i+1];
            }
            dp[i][prev+1]=max(take,ntake);
        }
    }

    // for(auto i:dp)
    // {
    //     for(auto j:i) cout<<j<<" ";
    //     cout<<endl;
    // }
    // cout<<dp[0][0];
}


//