// 3394. Check if Grid can be Cut into Sections
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool checkCuts(vector<vector<int>>& rectangles,int dim){
            sort(rectangles.begin(),rectangles.end(),[dim](vector<int>& a,vector<int>& b){
                return a[dim]<b[dim];
            });
    
            int gaps = 0 , farthest = rectangles[0][dim+2];
    
            for(int i=1;i<rectangles.size();i++){
                if(rectangles[i][dim]>=farthest)
                    gaps++;
    
                farthest = max(farthest,rectangles[i][dim+2]);   
            }
    
            return gaps>=2;
        }
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            return checkCuts(rectangles,0) || checkCuts(rectangles,1);
        }
    };