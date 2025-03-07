// 2523. Closest Prime Numbers in Range

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<bool> findPrime(){
            int n = 1e6+1;
            vector<bool> prime(n , true);
            prime[0] = prime[1] = false;
    
            for(int i=2;i<=n;i++){
                if(!prime[i])
                    continue;
    
                for(int j=2*i;j<=n;j += i){
                    prime[j] = false;
                }
            }
    
            return prime;
        }
        vector<int> closestPrimes(int left, int right) {
            vector<bool> prime = findPrime();
    
            vector<int> nums;
            for(int i=left;i<=right;i++){
                if(prime[i])
                    nums.push_back(i);
            }
    
            if(nums.size()<2)
                return {-1,-1};
            
            int req , diff = INT_MAX;
    
            for(int i=1;i<nums.size();i++){
                if(nums[i]-nums[i-1] < diff){
                    req = i;
                    diff = nums[i]-nums[i-1];
                }
            }
    
            return {nums[req-1] , nums[req]};
        }
    };