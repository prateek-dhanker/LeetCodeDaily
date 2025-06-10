// 3442. Maximum Difference Between Even and Odd Frequency
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        int maxOdd = INT_MIN, minEven =  INT_MAX;
        vector<int> freq(26,0);

        for(char ch: s)
            freq[ch-'a']++;
        
        for(int i=0;i<26;i++){
            if(freq[i]==0)
                continue;
            if(freq[i]&1)
                maxOdd = max(maxOdd, freq[i]);
            else
                minEven = min(minEven, freq[i]);
        }

        return maxOdd-minEven;
    }
};