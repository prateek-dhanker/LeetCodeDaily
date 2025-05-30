// 2359. Find Closest Node to Given Two Nodes
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<int> node1Traversal(n,-1);

        int temp = node1, path = 0;
        while(temp!=-1 && node1Traversal[temp]==-1){
            node1Traversal[temp] = path++;
            temp = edges[temp];
        }

        for(int i:node1Traversal)
            cout<<i<<" ";

        int mini = INT_MAX, minIdx = -1;
        path = 0;
        temp = node2;
        vector<int> vis(n,false);
        while(temp!=-1 && !vis[temp]){
            vis[temp] = true;
            if(node1Traversal[temp]!=-1 ){
                int res = max(node1Traversal[temp], path);

                if(res<mini || (res==mini && temp<minIdx)){
                    mini = res;
                    minIdx = temp;
                }
            }
            
            path++;
            temp = edges[temp];
        }

        return minIdx;
    }
};