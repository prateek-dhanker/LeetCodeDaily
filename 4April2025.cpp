// 1123. Lowest Common Ancestor of Deepest Leaves

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
        int heightPreorder(TreeNode* root,int depth,int& maxi,TreeNode* &res){
            if(root == NULL)
                return depth;
            
            int hl = heightPreorder(root->left,depth+1,maxi,res);
            int hr = heightPreorder(root->right,depth+1,maxi,res);
    
            if(hl == hr && hr>=maxi){
                res = root;
                maxi = hr;
            }
            
            return max(hl,hr);
        }
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            TreeNode* res = root;
            int maxi = 0;
    
            heightPreorder(root,0,maxi,res);
            cout<<res->val;
            return res;
        }
    };