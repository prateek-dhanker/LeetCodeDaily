// 3304. Find the K-th Character in String Game I
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        string res = "a";

        while(res.size()<k){
            string newStr = res;
            for(auto& ch : newStr){
                if(ch == 'z')
                    ch = 'a';
                else
                    ch++;
            }
            res += newStr;
        }

        return res[k-1];
    }
};