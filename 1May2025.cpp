// 2071. Maximum Number of Tasks You Can Assign

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            multiset<int> wset;
            for (int i = workers.size() - k; i < workers.size(); ++i)
                wset.insert(workers[i]);
    
            int remainingPills = pills;
    
            for (int i = k - 1; i >= 0; --i) {
                int task = tasks[i];
    
                auto it = wset.end();
                if (!wset.empty()) {
                    --it;
                    if (*it >= task) {
                        wset.erase(it);
                        continue;
                    }
                }
    
                auto it2 = wset.lower_bound(task - strength);
                if (it2 == wset.end() || remainingPills == 0)
                    return false;
    
                wset.erase(it2);
                remainingPills--;
            }
    
            return true;
        }
    
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            sort(tasks.begin(), tasks.end());
            sort(workers.begin(), workers.end());
    
            int low = 0, high = min(tasks.size(), workers.size()), ans = 0;
    
            while (low <= high) {
                int mid = (low + high) / 2;
                if (canAssign(mid, tasks, workers, pills, strength)) {
                    ans = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
    
            return ans;
        }
    };
    