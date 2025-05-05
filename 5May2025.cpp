// 790. Domino and Tromino Tiling

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numTilings(int n) {
            const int MOD = 1e9 + 7;
            if (n == 0) return 0;
            if (n == 1) return 1;
            if (n == 2) return 2;
    
            vector<long long> dp(n + 3);
            dp[0] = 1;
            dp[1] = 2;
            dp[2] = 5;
    
            for (int i = 3; i < n; ++i) {
                dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MOD;
            }
    
            return dp[n - 1];
        }
    };