#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void subsets(vector<int>& nums,int idx,int xori,int& sum){
            if(idx == nums.size()){
                sum += xori;
                return ;
            }
    
            subsets(nums,idx+1,xori,sum);
    
            subsets(nums,idx+1,xori^nums[idx],sum);
        }
        int subsetXORSum(vector<int>& nums) {
            int sum = 0;
    
            subsets(nums,0,0,sum);
    
            return sum;
        }
    };