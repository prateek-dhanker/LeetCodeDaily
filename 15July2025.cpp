// 3136. Valid Word
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        if(n <= 2)
            return false;

        int vowel = 0, cons = 0;

        for(char ch : word){
            if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
                    vowel++;
                else
                    cons++;
            }
            else if(ch <'0' || ch > '9')
                return false;
        }
        
        return vowel>=1 && cons>=1;
    }
};