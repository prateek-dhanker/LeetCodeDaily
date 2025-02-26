// 1749. Maximum Absolute Sum of Any Subarray

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int n = nums.size();
            int currSum = nums[0] , maxSum = nums[0];
    
            for(int i=1;i<n;i++){
                currSum = max(currSum + nums[i] , nums[i]);
                maxSum = max(maxSum,currSum);
            }
    
            int minSum = nums[0];
            currSum = nums[0] ;
    
            for(int i=1;i<n;i++){
                currSum = min(currSum + nums[i] , nums[i]);
                minSum = min(minSum,currSum);
            }
    
            return max(maxSum,abs(minSum));
        }
    };