// 2161. Partition Array According to Given Pivot 

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            list<int> small , large;
            int eq =  0;
    
            for(int i=0;i<nums.size();i++){
                if(nums[i]==pivot)
                    eq++;
                else if(nums[i]<pivot)
                    small.push_back(nums[i]);
                else
                    large.push_back(nums[i]);
            }
    
            vector<int> res;
            while(small.size()){
                res.push_back(small.front());
                small.pop_front();
            }
    
            while(eq--)
                res.push_back(pivot);
    
            while(large.size()){
                res.push_back(large.front());
                large.pop_front();
            }
    
            return res;
        }
    
    };