// 3341. Find Minimum Time to Reach Last Room I
#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
            vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
            int n = moveTime.size(), m = moveTime[0].size();
    
            vector<vector<long long>> dist(n,vector<long long>(m,LLONG_MAX));
            dist[0][0] = 0;
    
            priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    
            pq.push({0,{0,0}});
    
    
            while(pq.size()){
                auto top = pq.top();
                pq.pop();
                int cost = top.first, x=top.second.first, y= top.second.second;
    
                for(auto d:dirs){
                    int newx = x+d[0], newy = y+d[1];
    
                    if(newx >=0 && newy>=0 && newx<n && newy<m){
                        int time = 1;
                        if(moveTime[newx][newy]>cost)
                            time += (moveTime[newx][newy]-cost);
                        int tcost = cost+time;
                        
                        if(tcost<dist[newx][newy]){
                            dist[newx][newy] = tcost;
                            pq.push({tcost,{newx,newy}});
    
                            if(newx == n-1 && newy== m-1)
                                return dist[newx][newy];
                        }
                    }
                }
            }
    
            return -1;
        }
    };