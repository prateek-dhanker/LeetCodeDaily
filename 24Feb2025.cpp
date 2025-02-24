// 2467. Most Profitable Path in a Tree

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool bobyPath(vector<vector<int>> &adj,unordered_map<int,int> &bobby,vector<int> &vis,int node,int time){
            vis[node] = true;
            bobby[node] = time;
    
            if(node==0)
                return true;
            
            for(int nbr:adj[node]){
                if(!vis[nbr]){
                    bool isPath = bobyPath(adj,bobby,vis,nbr,time+1);
    
                    if(isPath)
                        return true;
                }                
            }
    
            bobby.erase(node);
            return false;
        }
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
            int n = amount.size();
    
            vector<vector<int>> adj(n);
    
            for(auto edge:edges){
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
    
            vector<int> vis(n,false);
    
            unordered_map<int,int> bobby;
            bobyPath(adj,bobby,vis,bob,0);
    
            queue<vector<int>> q;
            q.push({0,0,0});
    
            vis.assign(n,false);
            vis[0] = true;
    
            int maxi = INT_MIN;
    
            while(q.size()){
                auto curr = q.front();
                q.pop();
    
                int node = curr[0] , time = curr[1] , income = curr[2];
    
                if(bobby.find(node)==bobby.end() || time<bobby[node])
                        income += amount[node];
                    
                else if(time==bobby[node])
                    income += (amount[node]/2);
    
                if(node!=0 && adj[node].size()==1){
                    //leaf node
                    maxi = max(maxi,income);
                }
    
                for(int nbr:adj[node]){
                    if(!vis[nbr]){
                        vis[nbr] = true;
                        q.push({nbr,time+1,income});
                    }
                }
            }
    
            return maxi;
        }
    };