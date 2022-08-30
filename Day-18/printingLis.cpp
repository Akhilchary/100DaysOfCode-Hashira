#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums={5,4,11,1,16,8};
    int n=nums.size();
    vector<int> dp(n,1),hash(n,0);
    int idx=0,mx=0;
    for(int i=0;i<n;i++)
    {
        hash[i]=i;
        for(int prev=0;prev<i;prev++)
        {
            if(nums[i]>nums[prev] && 1+dp[prev]>dp[i])
            {
                dp[i]=1+dp[prev];
                hash[i]=prev;
            }
        }
        if(mx<dp[i])
        {
            mx=dp[i];
            idx=i;
        }
    }
    vector<int> tmp;
    tmp.push_back(nums[idx]);
    while(idx!=hash[idx])
    {
        idx=hash[idx];
        tmp.push_back(nums[idx]);
    }
    reverse(tmp.begin(),tmp.end());
    for(auto i:tmp) cout<<i<<" ";
    cout<<endl;
}