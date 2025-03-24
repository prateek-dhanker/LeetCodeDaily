// 3169. Count Days Without Meetings
#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            sort(meetings.begin(),meetings.end());
    
            vector<vector<int>> merged;
            merged.push_back(meetings[0]);
    
            int cnt = meetings[0][0]-1;
    
            for(int i=1;i<meetings.size();i++){
                if(meetings[i][0] <= merged.back()[1])
                    merged.back()[1] = max(merged.back()[1],meetings[i][1]);
                else{
                    cnt += (meetings[i][0] - merged.back()[1]-1);
                    merged.push_back(meetings[i]);
                }
            }
    
            cnt += (days-merged.back()[1]);
    
            return cnt;
        }
    };