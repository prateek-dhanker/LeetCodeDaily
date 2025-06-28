// 2099. Find Subsequence of Length K With the Largest Sum
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(const pair<int,int>& a,const pair<int,int>& b){
        return a.second < b.second;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> numIdx(n);

        for(int i=0;i<n;i++)
            numIdx[i] = {nums[i],i};
        
        sort(numIdx.rbegin(), numIdx.rend());

        vector<pair<int,int>> resIdx(k);
        for(int i=0;i<k;i++)
            resIdx[i] = numIdx[i];
        
        sort(resIdx.begin(),resIdx.end(),cmp);

        vector<int> res(k);
        for(int i=0;i<k;i++)
            res[i] = resIdx[i].first;

        return res;
    }
};