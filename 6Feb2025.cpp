#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> cnt;

        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n;j++){
                int prod = nums[i]*nums[j];
                res += cnt[prod]*8;
                cnt[prod]++;
            }
        }      

        return res;
    }
};