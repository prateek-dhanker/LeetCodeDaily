// 2294. Partition Array Such That Maximum Difference Is K
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int partitions = 0;
        int i=0;
        while(i<n){
            partitions++;

            int mini = nums[i];

            while(i<n && nums[i]-mini <= k)
                i++;
        }

        return partitions;
    }
};