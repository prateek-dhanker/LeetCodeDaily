// 1298. Maximum Candies You Can Get from Boxes
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> boxFound(n,false);

        int totalCandies = 0;
        queue<int> q;
        for(int ib : initialBoxes){
            if(status[ib]){
                q.push(ib);
                totalCandies += candies[ib];
                candies[ib] = 0;
            }
            else
                boxFound[ib] = true;
        }

        while(q.size()){
            int box = q.front();
            q.pop();

            for(int cb : containedBoxes[box]){
                boxFound[cb] = true;

                if(status[cb] && candies[cb]){
                    q.push(cb);
                    totalCandies += candies[cb];
                    candies[cb] = 0;
                }
            }

            for(int k : keys[box]){
                status[k] = true;

                if(boxFound[k] && candies[k]){
                    q.push(k);
                    totalCandies += candies[k];
                    candies[k] = 0;
                }
            }
        }

        return totalCandies;
    }
};