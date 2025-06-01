// 2929. Distribute Candies Among Children II
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long res = 0;

        limit = min(n,limit);

        for(int candiesFirst=0;candiesFirst<=limit;candiesFirst++){
            int rem = n - candiesFirst;

            if(rem > 2*limit)
                continue;
            
            res += min(rem,limit) - max(0,rem-limit) + 1;
        }

        return res;
    }
};