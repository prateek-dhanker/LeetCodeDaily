// 3335. Total Characters in String After Transformations I
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<int> freq(26,0);

        for(char& ch:s)
            freq[ch-'a']++;
        
        while(t--){
            vector<int> next(26);
            
            next[0] = freq[25];
            next[1] = (freq[25]+freq[0])%MOD;

            for(int i=2;i<26;i++)
                next[i] = freq[i-1];
            
            freq = next;
        }

        long long res = 0;
        for(int i=0;i<26;i++){
            res = (res+freq[i])%MOD;
        }

        return res;
    }
};