// 2685. Count the Number of Complete Components
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool complete(int n,vector<vector<int>>& adj,int node,vector<bool>& vis){
            vis[node] = true;
            int edges = 0,nodes=0;
    
            queue<int> q;
            q.push(node);
    
            while(q.size()){
                int curr = q.front();
                q.pop();
    
                nodes++;
    
                for(int nbr:adj[curr]){
                    edges++;
                    if(!vis[nbr]){
                        q.push(nbr);
                        vis[nbr] = true;
                    }
                }
            }
    
            edges /= 2;
    
            return (nodes*(nodes-1))/2 == edges;
        }
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            vector<vector<int>> adj(n);
            for(auto edge:edges){
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
            vector<bool> vis(n,false);
            
            int comp = 0;
            for(int i=0;i<n;i++){
                if(!vis[i] && complete(n,adj,i,vis))
                    comp++;
            }
            return comp;
        }
    };