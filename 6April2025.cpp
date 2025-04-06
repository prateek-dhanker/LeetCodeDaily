// 368. Largest Divisible Subset

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            int n = nums.size();
            sort(nums.begin(),nums.end());
    
            vector<int> dp(n,1) , findPrev(n);
    
            for(int i=0;i<n;i++)
                findPrev[i] = i;
    
            for(int i = 1;i<n;i++){
                for(int prev = 0;prev<i;prev++){
                    if(nums[i]%nums[prev]==0 && dp[i]<dp[prev]+1){
                        dp[i] = dp[prev]+1;
                        findPrev[i] = prev;
                    }
                }
            }
    
            int maxi = 1,idx = 0;
    
            for(int i=1;i<n;i++){
                if(dp[i]>maxi){
                    maxi= dp[i];
                    idx = i;
                }
            }
    
            vector<int> res(maxi);
            int k = maxi-1;
            while(findPrev[idx]!=idx){
                res[k--] = nums[idx];
                idx = findPrev[idx];
            }
    
            res[k] = nums[idx];
            return res;
        }
    };