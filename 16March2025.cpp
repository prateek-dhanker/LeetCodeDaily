// 2594. Minimum Time to Repair Cars
#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        bool possible(vector<int>& ranks, int cars,long long time){
            long long repairedCars = 0;
    
            for(int r : ranks){
                int rep = sqrt(time/r);
                repairedCars += rep;
            }
    
            return repairedCars>=cars;
        }
        long long repairCars(vector<int>& ranks, int cars) {
            long long s = *min_element(ranks.begin(),ranks.end()) , e = s*cars*cars;
    
            long long ans = -1;
            while(s<=e){
                long long mid = (s+e)/2;
    
                if(possible(ranks,cars,mid)){
                    ans = mid;
                    e = mid-1;
                }
                else
                    s = mid+1;
            }
            return ans;
        }
    };