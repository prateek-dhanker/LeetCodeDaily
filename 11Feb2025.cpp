#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        bool check(stack<char>& st,string &part){
            stack<char> temp = st;
            int j = part.length()-1;
    
            while(j>=0){
                if (temp.empty() || temp.top() != part[j]) 
                        return false;
                temp.pop();
                j--;
            }
            return true;
        }
        string removeOccurrences(string s, string part) {
            stack<char> st;
    
            for(int i=0;i<s.length();i++){
                st.push(s[i]);
    
                if(st.size()>=part.size() && s[i] == part.back() && check(st,part)){
                    for(int j=0;j<part.size();j++)
                        st.pop();
                }
            }
            string res = "";
    
            while(st.size()){
                res = st.top() + res;
                st.pop();
            }
    
            return res;
            
        }
    };