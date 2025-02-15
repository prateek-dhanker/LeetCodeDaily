// 2698. Find the Punishment Number of an Integer

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool possible(int num,int target){
            if(target<0 || num<target)
                return false;
            
            if(num == target)
                return true;
            
            return possible(num/10 , target-num%10) || possible(num/100 , target-num%100) || possible(num/1000 , target-num%1000);
        }
        int punishmentNumber(int n) {
            int res = 0;
    
            for(int i=1;i<=n;i++){
                if(possible(i*i,i))
                    res+= (i*i);
            }
    
            return res;
        }
    };