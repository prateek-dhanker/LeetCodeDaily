// 2140. Solving Questions With Brainpower

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long solve(vector<vector<int>>& questions,int idx,vector<long long>& dp){
            if(idx >= questions.size())
                return 0;
            
            if(dp[idx]!=-1)
                return dp[idx];
            
            int points = questions[idx][0], brainpower = questions[idx][1];
            
            long long exc = solve(questions,idx+1,dp);
    
            long long inc = points + solve(questions,idx+brainpower+1,dp);
    
            return dp[idx] = max(inc,exc);
        }
        long long mostPoints(vector<vector<int>>& questions) {
            int n = questions.size();
    
            vector<long long> dp(n,-1);
            return solve(questions,0,dp);
        }
    };