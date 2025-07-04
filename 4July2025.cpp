// 3307. Find the K-th Character in String Game II
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k == 1)
            return 'a';

        long long pow2 = 1, i=0;;

        while(pow2*2 < k){
            pow2 *= 2;
            i++;
        }
        
        char ch;
        if(k%pow2 == 0){
            ch = kthCharacter(pow2,operations);

            if(operations[i])
                ch = ch=='z' ? 'a' : ++ch;
        }
        else{
            ch = kthCharacter(k%pow2,operations);

            if(operations[i])
                ch = ch=='z' ? 'a' : ++ch;
        }

        return ch;

    }
};