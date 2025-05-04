// 1128. Number of Equivalent Domino Pairs
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            vector<vector<int>> freq(10,vector<int>(10,0));
    
            int cnt = 0;
    
            for(auto domino:dominoes){
                int d1 = min(domino[0],domino[1]), d2 = max(domino[0],domino[1]);
    
                if(freq[d1][d2]>1){
                    int n = freq[d1][d2];
                    cnt -= (n*(n-1))/2;
                }
                freq[d1][d2]++;
    
                if(freq[d1][d2]>1){
                    int n = freq[d1][d2];
                    cnt += (n*(n-1))/2;
                }
    
            }
            return cnt;
        }
    };