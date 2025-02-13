// 3066. Minimum Operations to Exceed Threshold Value II
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            int n = nums.size();
    
            priority_queue<long long,vector<long long>,greater<long long>> pq;
    
            for(int i=0;i<n;i++)
                pq.push(nums[i]);
            
            int oper = 0;
            while(pq.size()>1 && pq.top()<k){
                long long x = pq.top();
                pq.pop();
                
                long long y = pq.top();
                pq.pop();
    
                oper++;
    
                long long newElem = min(x,y)*2 + max(x,y);
                pq.push(newElem);
            }
    
            return oper;
        }
    };