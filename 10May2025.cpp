// 2918. Minimum Equal Sum of Two Arrays After Replacing Zeros
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long minSum(vector<int>& nums1, vector<int>& nums2) {
            long long sum1 = 0, sum2 = 0, z1=0, z2=0;
    
            for(int n:nums1){
                if(n)
                    sum1 += n;
                else
                    z1++;
            }
            for(int n:nums2){
                if(n)
                    sum2 += n;
                else
                    z2++;
            }
    
            if((z1==0 && sum1 < sum2+z2) || (z2==0 && sum1+z1>sum2))
                return -1;
            
            return  max(sum1+z1, sum2+z2);
        }
    };