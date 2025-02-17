// 1079. Letter Tile Possibilities

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void backtrack(string& tiles,string& s,vector<int>& freq,unordered_set<string>& st){
            if(s.size()==tiles.size()){
                st.insert(s);
                return;
            }
            if(s!="")
                st.insert(s);
            
            for(int i=0;i<26;i++){
                if(freq[i]){
                    freq[i]--;
                    s.push_back(i+'A');
                    backtrack(tiles,s,freq,st);
                    freq[i]++;
                    s.pop_back();
                }
            }
        }
        int numTilePossibilities(string tiles) {
            vector<int> freq(26,0);
    
            for(char ch:tiles)
                freq[ch-'A']++;
            
            string s = "";
            unordered_set<string> st;
    
            backtrack(tiles,s,freq,st);
    
            return st.size();
        }
    };