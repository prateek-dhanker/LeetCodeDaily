// 1751. Maximum Number of Events That Can Be Attended II
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int upper_bound_ev(vector<vector<int>>& events, int index, int endTime){
        int next = -1;

        int s = index, e = events.size()-1;
        while(s <= e){
            int mid = s + (e-s)/2;

            if(events[mid][0] > endTime){
                next = mid;
                e = mid-1;
            }
            else
                s = mid+1;
        }

        return next;
    }
    int attendMeetings(vector<vector<int>>& events, int k,int index,vector<vector<int>> &dp){
        if(index == events.size() || k == 0)
            return 0;
        
        if(dp[k][index]!=-1)
            return dp[k][index];
        
        int skip = attendMeetings(events,k,index+1,dp);

        int newIndex = upper_bound_ev(events, index, events[index][1]);
        int attend = events[index][2];
        if(newIndex != -1)
            attend += attendMeetings(events,k-1,newIndex,dp);

        return dp[k][index] = max(attend,skip);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>> dp(k+1, vector<int>(n, -1));

        return attendMeetings(events,k,0,dp);
    }
};