// 2942. Find Words Containing Character
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;

        for(int i=0;i<words.size();i++){
            bool found = false;
            for(char ch:words[i]){
                if(ch == x){
                    found = true;
                    break;
                }
            }

            if(found)
                res.push_back(i);
        }

        return res;
    }
};