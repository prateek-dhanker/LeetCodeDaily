// 2016. Maximum Difference Between Increasing Elements
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();

        int maxi = -1, maxElem = nums[n-1];
        for(int i=n-2; i>=0; i--){
            if(nums[i] >= maxElem)
                maxElem = nums[i];

            else
                maxi = max(maxi, maxElem - nums[i]);
        }

        return maxi;
    }
};