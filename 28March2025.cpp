// 2503. Maximum Number of Points From Grid Queries
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            int n=grid.size(), m=grid[0].size(), k=queries.size();
    
            vector<pair<int,int>> sortedq;
    
            for(int i=0;i<k;i++)
                sortedq.push_back({queries[i],i});
            
            sort(sortedq.begin(),sortedq.end());
    
            vector<int> res(k);
            vector<vector<bool>> vis(n,vector<bool>(m,false));
    
            priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    
            pq.push({grid[0][0],{0,0}});
            vis[0][0] = true;
    
            int cnt = 0;
            for(int i=0;i<k;i++){
                int q = sortedq[i].first , idx = sortedq[i].second;
    
                while(pq.size() && pq.top().first<q){
                    auto curr = pq.top();
                    pq.pop();
    
                    cnt++;
    
                    int x=curr.second.first, y=curr.second.second;
    
                    for(auto d:dir){
                        int newx = x+d[0] , newy= y+d[1];
    
                        if(newx>=0 && newx<n && newy>=0 && newy<m && !vis[newx][newy]){
                            vis[newx][newy] = true;
                            pq.push({grid[newx][newy], {newx,newy}});
                        }
                    }
                }
    
                res[idx] = cnt;
            }
    
            return res;
        }
    };