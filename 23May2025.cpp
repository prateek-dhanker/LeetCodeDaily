// 3068. Find the Maximum Sum of Node Values
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();

        vector<int> netChange(n);

        for(int i=0;i<n;i++)
            netChange[i] = (nums[i]^k) - nums[i];
        
        sort(netChange.rbegin(),netChange.rend());

        long long total = accumulate(nums.begin(),nums.end(),0LL);

        for(int i=0;i<n;i+=2){
            if(i+1==n)
                continue;
            
            long long change = netChange[i] + netChange[i+1];
            if(change>0)
                total += change;
        }

        return total;
    }
};