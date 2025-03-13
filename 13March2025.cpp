// 3356. Zero Array Transformation II 

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool possible(vector<int>& nums, vector<vector<int>>& queries,int k){
            int n = nums.size();
            vector<int> sweepline(n+1 , 0);
    
            for(int i=0;i<k;i++){
                auto q = queries[i];
    
                int l = q[0] , r = q[1] , val = q[2];
    
                sweepline[l] += val;
                sweepline[r+1] -= val;
            }
    
            for(int i=1;i<n+1;i++)
                sweepline[i] += sweepline[i-1];
            
            for(int i=0;i<n;i++){
                if(sweepline[i]<nums[i])
                    return false;
            }
    
            return true;
        }
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int n = nums.size();
    
            int s = 0,e = queries.size();
    
            int ans = -1;
            while(s<=e){
                int mid = (s+e)/2;
    
                if(possible(nums,queries,mid)){
                    ans = mid;
                    e = mid-1;
                }
                else
                    s = mid+1;
            }
    
            return ans;
        }
    };