// 3191. Minimum Operations to Make Binary Array Elements Equal to One I
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int n = nums.size();
            int op = 0;
    
            for(int i=0;i<=n-3;i++){
                if(nums[i]==0){
                    op++;
                    for(int j=i;j<i+3;j++)
                        nums[j] = nums[j] ? 0 : 1;
                }
            }
            for(int i=n-3;i<n;i++){
                if(nums[i]==0)
                    return -1;
            }
    
            return op;
        }
    };