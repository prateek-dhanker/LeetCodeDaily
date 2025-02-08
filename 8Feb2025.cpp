// 2349. Design a Number Container System

#include <bits/stdc++.h>
using namespace std;

class NumberContainers {
public:
    unordered_map<int,int> container;
    // unordered_map<pair<int,int>,bool> container;
    unordered_map<int,priority_queue<int,vector<int>,greater<int>>> pq;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        container[index] = number;
        pq[number].push(index);
    }
    
    int find(int number) {
        while(pq[number].size() && container[pq[number].top()] != number)
            pq[number].pop();
        
        return pq[number].size() ? pq[number].top() : -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */