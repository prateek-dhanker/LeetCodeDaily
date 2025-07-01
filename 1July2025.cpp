// 3330. Find the Original Typed String I
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int cnt = 1;
        int i=0, n=word.size();

        while(i<n){
            int j=i+1;
            while(j<n && word[j]==word[i]){
                j++;
                cnt++;
            }
            
            i=j;
        }

        return cnt;
    }
};