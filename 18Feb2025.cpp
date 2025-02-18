// 2375. Construct Smallest Number From DI String

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool possibleStrings(string& pattern , string& res, vector<bool>& digi){
            if(res.size() == pattern.size()+1)
                return true;
            
            int currIdx = res.size();
            
            for(int i=1;i<=9;i++){
                if(digi[i])
                    continue;
                if(currIdx==0 || (pattern[currIdx-1]=='I' && i>res.back()-'0') || (pattern[currIdx-1]=='D' && i<res.back()-'0')){
                
                    res.push_back(i+'0');
                    digi[i] = true;
                    bool b = possibleStrings(pattern ,res ,digi);
    
                    if(b)
                        return true;
                    
                    
                    res.pop_back();
                    digi[i] = false;
                }
            }
            return false;
        }
        string smallestNumber(string pattern) {
            vector<bool> digi(10,false);
            string res = "";
    
            possibleStrings(pattern , res , digi);
    
            return res;
        }
    };