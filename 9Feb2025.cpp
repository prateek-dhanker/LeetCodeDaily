// 2364. Count Number of Bad Pairs
#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            int n=nums.size();
            unordered_map<int,int> cnt;
    
            int total = (n*(n-1))/2 , good =0;
            for(int i=0;i<n;i++){
                good += cnt[nums[i]-i];
                cnt[nums[i]-i]++;
            }
            return total-good;
        }
    };