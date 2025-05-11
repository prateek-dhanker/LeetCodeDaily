// 1550. Three Consecutive Odds
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int odd = 0;

        for(int a:arr){
            if(a&1)
                odd++;
            else
                odd = 0;
            
            if(odd ==3 )
                return true;
        }

        return false;
    }
};