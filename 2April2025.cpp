// 2873. Maximum Value of an Ordered Triplet I

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
    
            long long maxA = nums[0], maxAB = LLONG_MIN, maxABC = 0;
    
            for(int j=1; j<n-1; j++){
                maxAB = max(maxAB,maxA-nums[j]);
                maxABC = max(maxABC, maxAB*nums[j+1]);
                maxA = max(maxA,1LL*nums[j]);
            }
    
            return maxABC;
        }
    };