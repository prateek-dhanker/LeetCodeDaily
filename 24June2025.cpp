// 2200. Find All K-Distant Indices in an Array
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        unordered_map<int,bool> keyIdx;

        unordered_set<int> s;
        for(int i=0;i<n;i++){
            if(nums[i] == key){
                for(int j=i;j<n && j<=i+k;j++)
                    s.insert(j);
                for(int j=i;j>=0 && j>=i-k;j--)
                    s.insert(j);
            }
        }

        vector<int> res(s.begin(),s.end());
        sort(res.begin(),res.end());

        return res;
    }
};