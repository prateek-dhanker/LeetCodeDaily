// 1920. Build Array from Permutation
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
            int n = nums.size();
    
            for(int i=0;i<n;i++){
                int target = nums[nums[i]]%n;
                nums[i] += target*n;
            }
    
            for(int i=0;i<n;i++)
                nums[i] /= n;
            
            return nums;
        }
    };