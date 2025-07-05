// 1394. Find Lucky Integer in an Array
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> freq;

        for(int& a: arr){
            freq[a]++;
        }

        int lucky = -1;
        for(auto& [num,f]: freq){
            if(num == f)
                lucky = max(lucky,num);
        }

        return lucky;
    }
};