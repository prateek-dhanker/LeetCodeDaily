// 3170. Lexicographically Minimum String After Removing Stars
#include <bits/stdc++.h>
using namespace std;

class cmp{
public:
    bool operator()(pair<char,int>& a, pair<char,int>& b){
        if(a.first == b.first)
            return a.second<b.second;
        return a.first>b.first;
    }
};
class Solution {
public:
    static bool cmp2(pair<char,int>& a, pair<char,int>& b){
        return a.second<b.second;
    }
    string clearStars(string s) {
        int n = s.length();

        priority_queue<pair<char,int>, vector<pair<char,int>>, cmp> pq;

        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                pq.pop();
            }
            else{
                pq.push({s[i],i});
            }

            cout<<pq.top().first;
        }

        vector<pair<char,int>> v;
        while(pq.size()){
            v.push_back(pq.top());
            pq.pop();
        }

        sort(v.begin(),v.end(),cmp2);

        string res = "";
        for(auto x:v)
            res.push_back(x.first);
        
        return res;

    }
};