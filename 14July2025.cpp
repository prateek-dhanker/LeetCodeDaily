// 1290. Convert Binary Number in a Linked List to Integer
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string res = "";

        while(head){
            res.push_back(head->val);
            head = head->next;
        }

        int cnt = 0;
        for(int i=0;i<res.size();i++)
            cnt = cnt*2 + res[i];
        
        return cnt;
    }
};