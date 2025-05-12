// 2094. Finding 3-Digit Even Numbers
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits){
        vector<int> freq(10,0);

        for(int digit:digits)
            freq[digit]++;

        
        vector<int> res;

        for(int num = 100;num<1000;num += 2){
            bool possible = true;
            unordered_map<int,int> freq3;
            int temp = num;

            while(temp){
                freq3[temp%10]++;

                if(freq3[temp%10]>freq[temp%10]){
                    possible = false;
                    break;
                }
                temp/=10;
            }

            if(possible)
                res.push_back(num);
        }

        return res;
    }
};