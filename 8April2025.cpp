// 3396. Minimum Number of Operations to Make Elements in Array Distinct

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            int start = 0, n = nums.size(),cnt = 0;
            unordered_map<int,int> m;
    
            for(int i=0;i<n;i++){
                if(m.find(nums[i])!=m.end()){
                    if(m[nums[i]]>=start){
                        cnt = (m[nums[i]]+3)/3;
                        start = cnt*3;
                    }
                }
                
                m[nums[i]] = i;
            }
    
            return cnt;
        }
    };