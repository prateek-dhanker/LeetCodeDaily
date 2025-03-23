// 1976. Number of Ways to Arrive at Destination
#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        const int MOD = 1e9+7;
        int countPaths(int n, vector<vector<int>>& roads) {
            vector<vector<pair<int,int>>> adj(n);
            for(auto road: roads){
                int u = road[0],v=road[1],time = road[2];
    
                adj[u].push_back({v,time});
                adj[v].push_back({u,time});
            }
    
            vector<long long> dist(n,LLONG_MAX) , paths(n,0); 
            dist[0] = 0;
            paths[0] = 1;
    
            priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> q;
            q.push({0,0});
    
            int mini = INT_MIN,cnt = 0;
    
            while(q.size()){
                auto curr = q.top();
                q.pop();
    
                long long t = curr.first , node = curr.second;
    
                for(auto nbr : adj[node]){
                    int nbrNode = nbr.first , time = nbr.second;
    
                    if(dist[nbrNode]>time+t){
                        dist[nbrNode] = time+t;
                        paths[nbrNode] = paths[node];
                        q.push({dist[nbrNode],nbrNode});
                    }
                    else if(dist[nbrNode] == time+t)
                        paths[nbrNode] = (paths[nbrNode] + paths[node])%MOD;
                }
            }
    
            return paths[n-1];
        }
    };