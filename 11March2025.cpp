// 1358. Number of Substrings Containing All Three Characters 

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numberOfSubstrings(string s) {
            int a=0,b=0,c=0;
            int n = s.length(),l=0,r=0;
            int cnt = 0;
    
            while(r<n){
                if(s[r]=='a')
                    a++;
                else if(s[r]=='b')
                    b++;
                else
                    c++;
                
                int s1 = 0;
                while(a && b && c){
                    s1++;
                    if(s[l]=='a')
                        a--;
                    else if(s[l]=='b')
                        b--;
                    else
                        c--;
                    l++;
                }
    
                int s2 = n-r;
    
                cnt += (s1*s2);
                r++;
            }
            return cnt;
        }
    };