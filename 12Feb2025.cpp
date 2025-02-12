// 2342. Max Sum of a Pair With Equal Sum of Digits

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int digiSum(int n){
            int sum =0 ;
            while(n){
                sum += n%10;
                n /= 10;
            }
            return sum;
        }
        int maximumSum(vector<int>& nums) {
            unordered_map<int,int> m;
    
            int maxi = -1;
    
            for(int i=0;i<nums.size();i++){
                int dsum = digiSum(nums[i]);
    
                if(m[dsum]){
                    maxi = max(maxi , nums[i]+m[dsum]);
                }
                m[dsum] = max(m[dsum],nums[i]);
            }
    
            return maxi;
        }
    };