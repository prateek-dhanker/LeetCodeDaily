// 2379. Minimum Recolors to Get K Consecutive Black Blocks

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int n = blocks.size();
            int whites = 0;
    
            for(int i=0;i<k;i++){
                whites += blocks[i]=='W';
            }
    
            int minPaint = whites;
    
            for(int i=k;i<n;i++){
                whites -= blocks[i-k]=='W';
                whites += blocks[i]=='W';
    
                minPaint = min(minPaint,whites);
            }
    
            return minPaint;
        }
    };