// 3085. Minimum Deletions to Make String K-Special
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26,0);

        for(char ch : word)
            freq[ch-'a']++;
        
        int minDel = INT_MAX;
        for(int i=0;i<26;i++){
            if(freq[i]==0)
                continue;
            int del = 0;
            for(int j=0;j<26;j++){
                if(freq[j] < freq[i])
                    del += freq[j];
                else if(freq[j] > freq[i]+k)
                    del += freq[j] - freq[i] - k;
            }

            minDel = min(minDel,del);
        }

        return minDel;
    }
};