// 2537. Count the Number of Good Subarrays
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long atMostK(vector<int>& nums, long long k){
            int n = nums.size();
    
            unordered_map<int,long long> freq;
    
            long long cnt = 0,res = 0;
            long long l=0,r=0;
    
            while(r<n){
                freq[nums[r]]++;
                long long f = freq[nums[r]];
    
                if(freq[nums[r]]>1){
                    cnt -= ((f-1)*(f-2))/2;
                    cnt += (f*(f-1))/2;
                }
    
                while(l<=r && cnt>k){
                    int f = freq[nums[l]];
                    freq[nums[l]]--;
                    if(f>=1){
                        cnt -= (f*(f-1))/2;
                        cnt += ((f-1)*(f-2))/2;
                    }
                    l++;
                }
    
                res += (r-l+1);
                r++;
            }
    
            return res;
        }
        long long countGood(vector<int>& nums, int k) {
            int n = nums.size();
            long long maxPairs = (1LL*n*(n-1))/2;
    
            return atMostK(nums,maxPairs) - atMostK(nums,k-1);
        }
    };