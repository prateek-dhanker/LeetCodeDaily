// 2566. Maximum Difference by Remapping a Digit
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string numStr = to_string(num);
        
        int size = numStr.size();
        string mini = numStr;
        int i=0;
        while(i<size && mini[i]=='0')
            i++;
        char ch;
        if(i<size)
            ch = mini[i];
        while(i<size){
            if(mini[i] == ch)
                mini[i] = '0';
            i++;
        }

        int minNum = stoi(mini);

        string maxi = numStr;
        i=0;
        while(i<size && maxi[i]=='9')
            i++;
            
        if(i<size)
            ch = maxi[i];
        while(i<size){
            if(maxi[i] == ch)
                maxi[i] = '9';
            i++;
        }
        int maxNum = stoi(maxi);

        return maxNum-minNum;
    }
};