// 135. Candy
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> candies(n,1);

        for(int child=1;child<n;child++){
            if(ratings[child-1] < ratings[child])
                candies[child] = candies[child-1]+1;
        }

        for(int child=n-2;child>=0;child--){
            if(ratings[child+1]<ratings[child] && candies[child]<=candies[child+1])
                candies[child] = candies[child+1]+1;
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }
};