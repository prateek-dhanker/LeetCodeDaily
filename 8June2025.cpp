// 386. Lexicographical Numbers
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int curr = 1;
        vector<int> res;

        for(int i=0;i<n;i++){
            res.push_back(curr);

            if(curr*10 <=n)
                curr *= 10;
            
            else{
                while(curr >= n || curr%10 == 9)
                    curr /= 10;
                
                curr++;
            }
        }
        return res;
    }
};