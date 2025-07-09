// 3439. Reschedule Meetings for Maximum Free Time I
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        int maxi = 0, sum=startTime[0];
        int l=0;

        for(int r=0; r<n ;r++){
            if(r-l+1 > k){
                sum -= startTime[l];

                if(l)
                    sum += endTime[l-1];
                
                l++;
            }

            sum -= endTime[r];
            sum += r==n-1 ? eventTime : startTime[r+1];

            maxi = max(sum,maxi); 
        }
        return maxi;
    }
};