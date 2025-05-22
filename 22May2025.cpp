// 3362. Zero Array Transformation III

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        sort(queries.begin(),queries.end());

        vector<int> deltaArray(n+1,0);
        priority_queue<int> pq;
        
        int j=0, ops= 0;
        for(int i=0;i<n;i++){
            ops += deltaArray[i];

            while(j<q && queries[j][0]==i)
                pq.push(queries[j++][1]);

            while(ops<nums[i] && pq.size() && pq.top()>=i){
                deltaArray[pq.top()+1]--;
                pq.pop();
                ops++;
            }

            if(ops<nums[i])
                return -1;
        }
        
        return pq.size();
    }
};