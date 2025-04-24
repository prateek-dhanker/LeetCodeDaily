// 2799. Count Complete Subarrays in an Array

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            int n = nums.size();
            unordered_set<int> s;
    
            for(int num:nums)
                s.insert(num);
            
            int need = s.size();
    
            int l=0,r =0;
            int cnt = 0, have= 0;
            unordered_map<int,int> freq;
    
            while(r<n){
                freq[nums[r]]++;
    
                if(freq[nums[r]]==1)
                    have++;
                
                if(have == need){
                    int ls = 0;
                    while(have>=need){
                        ls++;
                        freq[nums[l]]--;
    
                        if(freq[nums[l]] == 0)
                            have--;
                        
                        l++;
                    }
                        cnt += ls*(n-r);
                }
                r++;
            }
            return cnt;
        }
    };