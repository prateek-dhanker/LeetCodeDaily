// 2780. Minimum Index of a Valid Split
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int n = nums.size();
            unordered_map<int,int> freq,curr;
    
            for(int n : nums)
                freq[n]++;
            
            for(int i=0;i<n-1;i++){
                int f = ++curr[nums[i]];
    
                bool left = f > (i+1)/2;
                bool right = freq[nums[i]]-f > (n-i-1)/2;
    
                if(left && right)
                    return i;
            }
            return -1;
        }
    };