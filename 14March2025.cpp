// 2226. Maximum Candies Allocated to K Children

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool possible(vector<int>& candies, long long k,int pile){
            for(int c:candies){
                k -= (c/pile);
            }
            return k<=0;
        }
        int maximumCandies(vector<int>& candies, long long k) {
            int s = 1, e = *max_element(candies.begin() , candies.end());
    
            int res = 0;
            while(s<=e){
                int mid = (s+e)/2;
    
                if(possible(candies,k,mid)){
                    res = mid;
                    s = mid+1;
                }
                
                else
                    e = mid-1;
            }
    
            return res;
    
        }
    };