// 2145. Count the Hidden Sequences

#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            long long curr = 0, maxi = INT_MIN, mini = INT_MAX;
    
            for(int d:differences){
                curr += d;
                maxi = max(maxi, curr);
                mini = min(mini, curr);
            }
    
            int total = upper-lower+1;
            if(mini<0)
                total += mini;
            
            if(maxi>0)
                total -= maxi;
            
            return total>0 ? total : 0;
        }
    };