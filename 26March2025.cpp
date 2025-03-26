// 2033. Minimum Operations to Make a Uni-Value Grid
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            int n = grid.size(), m = grid[0].size();
    
            int rem = grid[0][0]%x;
            vector<int> nums;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]%x != rem)
                        return -1;
                    nums.push_back(grid[i][j]);
                }
            }
    
            sort(nums.begin(),nums.end());
            int uni = nums[nums.size()/2];
    
            int ops = 0;
            for(int num:nums)
                ops += (abs(num-uni))/x;
            
            return ops;
        }
    };