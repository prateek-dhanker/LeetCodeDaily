// 909. Snakes and Ladders
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> moveTo(n * n + 1, -1);
        int label = 1;
        bool leftToRight = true;

        for (int i = n - 1; i >= 0; i--) {
            if (leftToRight) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] != -1)
                        moveTo[label] = board[i][j];
                    label++;
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    if (board[i][j] != -1)
                        moveTo[label] = board[i][j];
                    label++;
                }
            }
            leftToRight = !leftToRight;
        }

        queue<pair<int,int>> pq;
        pq.push({0,1});

        vector<bool> vis(n * n + 1, false);
        vis[1] = true;

        while (!pq.empty()) {
            auto [moves, curr] = pq.front();
            pq.pop();

            if (curr == n * n)
                return moves;

            for (int i = 1; i <= 6; i++) {
                int next = curr + i;
                if (next > n * n) continue;

                int dest = (moveTo[next] == -1) ? next : moveTo[next];

                if (!vis[dest]) {
                    vis[dest] = true;
                    pq.push({moves + 1, dest});
                }
            }
        }

        return -1;
    }
};