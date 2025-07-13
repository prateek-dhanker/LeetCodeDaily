// 2410. Maximum Matching of Players With Trainers
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size(), m = trainers.size();

        sort(players.rbegin(), players.rend());
        sort(trainers.rbegin(), trainers.rend());

        int j=0;
        for(int i=0; i<n && j<m;i++){
            if(players[i] <=  trainers[j])
                j++;
        }

        return j;
    }
};