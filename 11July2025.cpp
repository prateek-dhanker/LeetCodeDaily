// 2402. Meeting Rooms III
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> res(n,0);

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> pq;
        priority_queue<int,vector<int>,greater<>> emptyRooms;
        for(int i=0;i<n;i++)
            emptyRooms.push(i);
        
        int m = meetings.size();
        sort(meetings.begin(),meetings.end());
        for(int i=0;i<m;i++){
            while(pq.size() && pq.top().first <= meetings[i][0]){
                int room = pq.top().second;
                pq.pop();

                emptyRooms.push(room);
            }
            if(emptyRooms.size()){
                int room = emptyRooms.top();
                emptyRooms.pop();

                pq.push({meetings[i][1], room});
                res[room]++;
            }
            else{
                auto top = pq.top();
                pq.pop();
                pq.push({top.first + 1LL*(meetings[i][1] - meetings[i][0]),top.second});
                res[top.second]++;
            }
        }

        int maxi = res[0], maxRoom = 0;

        for(int i=0;i<n;i++){
            if(res[i] > maxi){
                maxi = res[i];
                maxRoom = i;
            }
        }

        return maxRoom;

    }
};