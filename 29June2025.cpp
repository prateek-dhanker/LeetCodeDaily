// 1498. Number of Subsequences That Satisfy the Given Sum Condition
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long long MOD = 1e9+7;
    long long expo(long long x,long long n){
        long long res = 1;
        while(n){
            if(n&1)
                res = (res*x)%MOD;
            
            x = (x*x)%MOD;
            n = n>>1;
        }

        return res;
    }
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int s = 0, e = n-1;
        long long res = 0;
        while(s<=e){
            while(s<=e && nums[s]+nums[e] > target)
                e--;

            if(s>e)
                break;
            
            long long len = e-s+1;
            long long reqSubseq = expo(2,len-1);
            res = (res + reqSubseq)%MOD;
            s++;
        }

        return res;
    }
};