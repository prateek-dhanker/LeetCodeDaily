// 2460. Apply Operations to an Array

#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        vector<int> applyOperations(vector<int>& arr) {
            int n = arr.size();
    
            int idx = 0,i=0;
            
            while(i<n-1){
                if(arr[i]==0)
                    i++;
                else if(arr[i] == arr[i+1]){
                    arr[idx++] = arr[i]*2;
                    i+=2;
                }
                else{
                    arr[idx++] = arr[i];
                    i++;
                }
            }
            if(i<n)
                arr[idx++] = arr[i];
    
            while(idx<n)
                arr[idx++] = 0;
    
            return arr;
        }
    };