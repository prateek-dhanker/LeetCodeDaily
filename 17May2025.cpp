// 75. Sort Colors

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int l = 0;

        while(l<n && nums[l]==0){
            l++;
        }

        if(l>=n)
            return;
        
        for(int r=l+1;r<n;r++){
            if(nums[r] == 0){
                swap(nums[r],nums[l++]);
            }
        }

        while(l<n && nums[l]==1){
            l++;
        }

        if(l>=n)
            return;
        
        for(int r=l+1;r<n;r++){
            if(nums[r] == 1){
                swap(nums[r],nums[l++]);
            }
        }        

    }
};