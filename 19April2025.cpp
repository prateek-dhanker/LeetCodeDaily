// 2563. Count the Number of Fair Pairs
#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        long long numLess(vector<int> &nums , int n){
            long long ans=0;
            int s= 0 , e = nums.size()-1;
    
            while(s<e){
                while(s<e && nums[s]+nums[e]>n)
                    e--;
                ans += e-s;
                s++;
            }
            return ans;
        }
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            sort(nums.begin() , nums.end());
    
            return numLess(nums,upper)-numLess(nums,lower-1);
    
        }
    };