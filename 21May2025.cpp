// 73. Set Matrix Zeroes
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();

        bool zeroFirstCol = false, zeroFirstRow = false;
        for(int row=0;row<n;row++)
            if(matrix[row][0] == 0){
                zeroFirstCol = true;
                break;
            }
        for(int col=0;col<m;col++)
            if(matrix[0][col] == 0){
                zeroFirstRow = true;
                break;
            }

        for(int row=1;row<n;row++)
            for(int col=1;col<m;col++)
                if(matrix[row][col] == 0){
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
        
        for(int row=1;row<n;row++)
            if(matrix[row][0] == 0)
                for(int col = 1;col<m;col++)
                    matrix[row][col] = 0;

        for(int col=1;col<m;col++)
            if(matrix[0][col] == 0)
                for(int row = 1;row<n;row++)
                    matrix[row][col] = 0;
        
        if(zeroFirstRow)
            for(int col = 0;col<m;col++)
                matrix[0][col] = 0;

        
        if(zeroFirstCol)
            for(int row = 0;row<n;row++)
                matrix[row][0] = 0;
    }
};