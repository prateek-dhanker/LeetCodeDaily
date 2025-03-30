// 763. Partition Labels
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> partitionLabels(string s) {
            int n = s.length();
            unordered_map<char,int> lastOccur;
    
            for(int i=0;i<n;i++)
                lastOccur[s[i]] = i;
            
            vector<int> res;
            int i=0;
    
            while(i<n){
                int len = 0, maxi = lastOccur[s[i]];
    
                while(i<=maxi){
                    len++;
                    maxi = max(maxi, lastOccur[s[i]]);
                    i++;
                }
    
                res.push_back(len);
            }
    
            return res;
        }
    };