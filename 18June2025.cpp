// 2966. Divide Array Into Arrays With Max Difference
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        vector<vector<int>> res;
        for(int i=0;i<n;i+=3){
            if(nums[i+2]-nums[i] > k)
                return {};
            
            vector<int> temp;
            for(int j=0;j<3;j++)
                temp.push_back(nums[i+j]);
            
            res.push_back(temp);
        }

        return res;
    }
};