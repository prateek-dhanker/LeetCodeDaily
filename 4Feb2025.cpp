#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi = nums[0] , curr = nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1])
                curr += nums[i];
            else
                curr = nums[i];
            
            maxi = max(maxi,curr);
        }

        return maxi;
    }
};