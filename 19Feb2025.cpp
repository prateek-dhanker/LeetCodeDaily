// 1415. The k-th Lexicographical String of All Happy Strings of Length n 

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool createString(int& n,int& k,string& res){        
            if(res.length()==n){
                k--;
                if(k==0)
                    return true;
                return false;
            }
    
            for(char ch = 'a';ch<='c';ch++){
                if(res.size() && res.back()==ch)
                    continue;
                
                res.push_back(ch);
    
                bool check = createString(n,k,res);
                if(check)
                    return true;
                
                res.pop_back();
            }
            return false;
    
        }
        string getHappyString(int n, int k) {
            string res = "";
    
            createString(n,k,res);
    
            return res;
        }
    };