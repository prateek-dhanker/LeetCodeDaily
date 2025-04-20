// 781. Rabbits in Forest
#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            unordered_map<int,int> freq;
    
            for(int ans : answers)
                freq[ans]++;
    
            int res = 0;
            
            for(auto& x : freq){
                int sameColorRabits = x.first, cnt = x.second;
    
                sameColorRabits++;
    
                int groups = (cnt+sameColorRabits-1)/sameColorRabits;
    
                res += (groups*sameColorRabits);
            }
    
            return res;
        }
    };