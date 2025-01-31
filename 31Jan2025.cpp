#include <bits/stdc++.h>
using namespace std;

class DisjointSetUnion{
public :
    vector<int> parent;
    vector<int> islandSize;
    DisjointSetUnion(int n){
        parent.resize(n);
        islandSize.resize(n,1);

        for(int i=0;i<n;i++)
            parent[i] = i;
    }

    int findParent(int node){
        if(parent[node] == node)
            return  node;
        
        return parent[node] = findParent(parent[node]);
    }
    
    void unionNodes(int u,int v){
        u = findParent(u);
        v = findParent(v);

        if(u==v)
            return;
        
        if(islandSize[u] < islandSize[v]){
            parent[u] = v;
            islandSize[v] += islandSize[u];
        }
        else {
            parent[v] = u;
            islandSize[u] += islandSize[v];
        }
    }
};
class Solution {
public:
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();

        DisjointSetUnion DSU(n*m);

        for(int row=0;row<n;row++){
            for(int col = 0;col<m;col++){
                if(grid[row][col]){
                    int curr = row*m + col;

                    for(auto d:dirs){
                        int x = row+d[0] , y = col + d[1];

                        if(x>=0 && y>=0 && x<n && y<m && grid[x][y]){
                            int nbr = x*m + y;
                            DSU.unionNodes(curr,nbr);
                        }
                    }
                }
            }
        }

        int maxi=0;
        bool hasZero = false;

        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col]==0){
                    hasZero = true;
                    int size = 1;
                    unordered_set<int> parents;

                    for(auto d:dirs){
                        int x = row+d[0] , y = col + d[1];

                        if(x>=0 && y>=0 && x<n && y<m && grid[x][y]){
                            int nbr = x*m + y;
                            parents.insert(DSU.findParent(nbr));
                        }
                    }

                    for(int parent:parents)
                        size += DSU.islandSize[parent];

                    maxi = max(maxi,size);
                }
            }
        }
        if(hasZero)
            return maxi;
        
        return n*m;
    }
};