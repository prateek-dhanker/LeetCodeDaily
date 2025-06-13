// 2616. Minimize the Maximum Difference of Pairs
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possible(vector<int>& nums, int p, int res) {
        int count = 0;
        for (int i = 0; i < nums.size() - 1;) {
            if (nums[i + 1] - nums[i] <= res) {
                count++;
                i += 2; // take this pair, skip next
            } else {
                i++; // skip current, try next
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int left = 0, right = nums.back() - nums.front();
        int answer = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (possible(nums, p, mid)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }
};