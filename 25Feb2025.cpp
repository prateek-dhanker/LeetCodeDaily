// 1524. Number of Sub-arrays With Odd Sum

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        const int MOD = 1e9+7;
        int numOfSubarrays(vector<int>& arr) {
            int n = arr.size();
            vector<int> prefix(n);
    
            prefix[0] = arr[0];
            for(int i=1;i<n;i++)
                prefix[i] = prefix[i-1]+arr[i];
            
            int oddSum = 0,evenSum = 0;
    
            int total = 0;
    
            for(int i=0;i<n;i++){
                if(prefix[i]&1){
                    oddSum++;
                    total  = (total + evenSum+1)%MOD;
                }
                else{
                    total = (total+oddSum)%MOD;
                    evenSum++;
                }
            }
            return total;
        }
    };