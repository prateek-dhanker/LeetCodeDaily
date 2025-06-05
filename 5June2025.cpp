// 1061. Lexicographically Smallest Equivalent String
#include <bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> parent;
public:
    DSU(){
        parent.resize(26);
        for(int i=0;i<26;i++)
            parent[i] = i;
    }
    int findParent(int node){
        if(parent[node] == node)
            return node;
        
        return parent[node] = findParent(parent[node]);
    }

    void unionNodes(int u,int v){
        u = findParent(u);
        v = findParent(v);

        if(u == v)
            return;
        
        if(u<v)
            parent[v] = u;
        else
            parent[u] = v;
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU dsu;
        int n = s1.length();
        for(int i=0;i<n;i++){
            dsu.unionNodes(s1[i]-'a', s2[i]-'a');
        }

        string res = "";
        for(int i=0;i<baseStr.length();i++)
            res.push_back('a' + (dsu.findParent(baseStr[i]-'a')));
        
        return res;
    }
};