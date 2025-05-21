// 3355. Zero Array Transformation I
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> sweepline(n+1,0);
    
        for(auto q:queries){
            int l = q[0] , r = q[1];

            sweepline[l]++;
            sweepline[r+1]--;
        }

        for(int i=1;i<n+1;i++)
            sweepline[i] += sweepline[i-1];
        
        for(int i=0;i<n;i++){
            if(sweepline[i]<nums[i])
                return false;
        }

        return true;
    }
};