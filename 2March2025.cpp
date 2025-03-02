// 2570. Merge Two 2D Arrays by Summing Values 

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            int n1 = nums1.size() , n2 = nums2.size();
    
            vector<vector<int>> res;
    
            int i=0 , j=0;
            while(i<n1 && j<n2){
                if(nums1[i][0]==nums2[j][0]){
                    res.push_back({nums1[i][0] , nums1[i][1] + nums2[j][1]});
                    i++;    
                    j++;
                }
                else if(nums1[i][0]<nums2[j][0]){
                    res.push_back(nums1[i]);
                    i++;
                }
                else{
                    res.push_back(nums2[j]);
                    j++;
                }
            }
            while(i<n1){
                res.push_back(nums1[i]);
                i++;
            }
            while(j<n2){
                res.push_back(nums2[j]);
                j++;
            }
    
            return res;
        }
    };