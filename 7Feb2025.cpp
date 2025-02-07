// 3160. Find the Number of Distinct Colors Among the Balls
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int total = 0;
        unordered_map<int,int> colors;
        unordered_map<int,int> colorCnt;

        vector<int> res;

        for(auto& q:queries){
            int ball = q[0] , col = q[1];

            if(colors[ball]){
                if(--colorCnt[colors[ball]] == 0)
                    total--;
            }
            
            if(++colorCnt[col] == 1)
                total++;
            colors[ball] = col;

            res.push_back(total);
        }

        return res;
    }
};