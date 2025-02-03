#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi = 1 , type = 0,curr=1;

        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                if(type != 1)
                    curr = 2;
                else
                    curr++;
                
                type = 1;
            }
            else if(nums[i]<nums[i-1]){
                if(type != 2)
                    curr = 2;
                else
                    curr++;
                
                type = 2;
            }
            else{
                curr = 1;
                type = 0;
            }

            maxi = max(maxi,curr);
        }

        return maxi;
    }
};