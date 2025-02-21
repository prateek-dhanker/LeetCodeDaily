// 1261. Find Elements in a Contaminated Binary Tree

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

class FindElements {
    public:
        unordered_map<int,bool> isPresent;
        void correctTree(TreeNode *root){
            int x = root->val;
            if(root->left){
                root->left->val = 2*x+1;
                isPresent[2*x+1] = true;
                correctTree(root->left);
            }
            
            if(root->right){
                root->right->val = 2*x+2;
                isPresent[2*x+2] = true;
                correctTree(root->right);
            }
    
        }
        FindElements(TreeNode* root) {
            root->val = 0;
            isPresent[0] = true;
            correctTree(root);
        }
        
        bool find(int target) {
            return isPresent[target];
        }
    };
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */