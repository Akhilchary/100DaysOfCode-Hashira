#include<bits/stdc++.h>
using namespace  std;
int main()
{
    //lis with binary search
    vector<int> nums={5,4,11,1,16,8};
    int n=nums.size();
    vector<int> tmp;
    tmp.push_back(nums[0]);
    for(int i=1;i<n;i++)
    {
        if(nums[i]>tmp.back())
        {
            tmp.push_back(nums[i]);
        }
        else{
            int ind=lower_bound(tmp.begin(),tmp.end(),nums[i])-tmp.begin();
            tmp[ind]=nums[i];
        }
    }
    cout<<tmp.size()<<endl;

}

