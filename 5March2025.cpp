// 2579. Count Total Number of Colored Cells

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long coloredCells(int n) {
            return 1LL*2*n*n - (2*n-1); 
        }
    };