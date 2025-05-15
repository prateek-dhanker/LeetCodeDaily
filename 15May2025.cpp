// 2900. Longest Unequal Adjacent Groups Subsequence I
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res;
        res.push_back(words[0]);

        int currGrp = groups[0];

        for(int i=1;i<groups.size();i++){
            if(groups[i]!=currGrp){
                res.push_back(words[i]);
                currGrp = groups[i];
            }
        }

        return res;
    }
};