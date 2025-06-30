// 594. Longest Harmonious Subsequence
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(int num : nums)
            freq[num]++;

        int maxi=0;
        for(auto& x:freq){
            int num=x.first, f=x.second;

            if(freq.find(num+1)!=freq.end()){
                maxi = max(maxi, freq[num+1]+f);
            }
        }   
        return maxi;
    }
};