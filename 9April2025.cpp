// 3375. Minimum Operations to Make Array Values Equal to K
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            unordered_set<int> s;
    
            for(int i=0;i<nums.size();i++){
                if(nums[i]<k)
                    return -1;
                else if(nums[i]>k)
                    s.insert(nums[i]);
            }
    
            return s.size();
        }
    };