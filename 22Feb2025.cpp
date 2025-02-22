// 1028. Recover a Tree From Preorder Traversal

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        int findDepth(string& traversal,int index){
            int cnt = 0;
    
            while(index<traversal.size() && traversal[index]=='-'){
                cnt++;
                index++;
            }
            return cnt;
        }
        int findVal(string& traversal,int& index){
            string num = "";
    
            while(index<traversal.size() && traversal[index]!='-'){
                num.push_back(traversal[index]);
                index++;
            }
            return stoi(num);
        }
        TreeNode* recoverUtil(string& traversal,int& index,int depth){
            if(index>=traversal.size())
                return NULL;
            
            int val = findVal(traversal,index);
    
            TreeNode* root = new TreeNode(val);
    
            if(index>=traversal.size())
                return root;
    
            int d = findDepth(traversal,index);
            if(d<=depth)
                return root;
            
            else
                index+=d;
            
            root->left = recoverUtil(traversal,index,d);
    
            d = findDepth(traversal,index);
            if(d<=depth)
                return root;
            else
                index+=d;
            
                
            root->right = recoverUtil(traversal,index,d);
    
            return root;
        }
        TreeNode* recoverFromPreorder(string traversal) {
            int index = 0;
            return recoverUtil(traversal,index,0);
        }
    };