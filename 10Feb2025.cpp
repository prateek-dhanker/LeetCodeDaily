// 3174. Clear Digits

#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        string clearDigits(string s) {
            string res;
    
            for(int i=0;i<s.length();i++){
                if(s[i]<='9' && s[i]>='0')
                    res.pop_back();
                else
                    res.push_back(s[i]);
            }
            return res;
        }
    };