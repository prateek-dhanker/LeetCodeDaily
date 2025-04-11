// 2843. Count Symmetric Integers
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int cnt = 0;
    
            for(int n=low;n<=high;n++){
                string num = to_string(n);
    
                if(num.size()&1)    
                    continue;
                
                int left = 0;
                for(int i=0;i<num.size()/2;i++)
                    left += num[i]-'0';
                
                int right = 0;
                for(int i=num.size()/2;i<num.size();i++)
                    right += num[i]-'0';
                
                if(left == right)
                    cnt++;
            }
    
            return cnt;
        }
    };