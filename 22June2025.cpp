// 2138. Divide a String Into Groups of Size k
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        vector<string> res;
        
        for(int i=0; i<n ;i+=k){
            string group = "";
            for(int j=i;j<n && j<i+k;j++)
                group.push_back(s[j]);
            
            while(group.size()<k)
                group.push_back(fill);

            res.push_back(group);
        }

        return res;
    }
};