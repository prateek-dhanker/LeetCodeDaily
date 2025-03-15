// 2560. House Robber IV 

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool possible(vector<int>& nums, int k,int caps){
            int thefts = 0;
    
            int i = 0;
            while(i<nums.size()){
                if(nums[i]<= caps){
                    thefts++;
                    i++;
                }
                i++;
            }
    
            return thefts>=k;
        }
        int minCapability(vector<int>& nums, int k) {
            int s = *min_element(nums.begin(),nums.end()) , e = *max_element(nums.begin(),nums.end());
    
            int ans = 0;
            while(s<=e){
                int mid = (s+e)/2;
                if(possible(nums,k,mid)){
                    ans = mid;
                    e = mid-1;
                }
                else
                    s = mid+1;
            }
    
            return ans;
        }
    };