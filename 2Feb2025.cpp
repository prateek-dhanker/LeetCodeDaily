#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int pivot =  false;

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                if(!pivot)
                    pivot = true;
                else
                    return false;
            }
        }
        if(!pivot) return true;
        return nums[0]>=nums[nums.size()-1];
    }
};