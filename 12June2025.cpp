// 3423. Maximum Difference Between Adjacent Elements in a Circular Array
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size(), maxi = INT_MIN;

        for(int i=0;i<n;i++)
            maxi = max(maxi, abs(nums[i] - nums[(i+1)%n]));
        
        return maxi;
    }
};