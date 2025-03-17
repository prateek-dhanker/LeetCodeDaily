// 2206. Divide Array Into Equal Pairs

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            unordered_map<int,int> m;
    
            for(int n:nums)
                m[n]++;
            
            for(auto& [n,cnt]:m){
                if(cnt&1)
                    return false;
            }
    
            return true;
        }
    };