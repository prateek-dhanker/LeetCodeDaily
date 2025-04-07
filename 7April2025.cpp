// 416. Partition Equal Subset Sum
#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        bool subset(vector<int>& nums,int index,int sum,int total,vector<vector<int>> &dp){
            if(sum == total)
                return true;
    
            if(sum>total || index==nums.size())
                return false;
            
            if(dp[index][sum]!=-1)
                return dp[index][sum];
            
            bool exc = subset(nums,index+1,sum,total,dp);
    
            bool inc = subset(nums,index+1,sum+nums[index],total,dp);
    
            return dp[index][sum] =  exc || inc;
        }
        bool canPartition(vector<int>& nums) {
            int total = accumulate(nums.begin(),nums.end(),0);
    
            if(total & 1)
                return false;
            
            vector<vector<int>> dp(nums.size() , vector<int>(total,-1));
            
            return subset(nums,0,0,total/2,dp);
        }
    };