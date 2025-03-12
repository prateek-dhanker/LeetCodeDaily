// 2529. Maximum Count of Positive Integer and Negative Integer
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int n = nums.size() ,neg = 0,z=0;
    
            for(int i=0;i<n;i++){
                if(nums[i]<0)
                    neg++;
                else if(nums[i]==0)
                    z++;
                else
                    break;
            }
    
            int pos = n-neg-z;
            return max(neg,pos);
        }
    };