#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> cnt(26,0);
        int diff = 0;

        for(int i=0;i<s1.length();i++){
            cnt[s1[i]-'a']++;
            cnt[s2[i]-'a']--;
            if(s1[i]!=s2[i])
                diff++;
        }
        if(diff>2)
            return false;
        
        for(int i=0;i<26;i++){
            if(cnt[i])
                return false;
        }
        return true;
    }
};