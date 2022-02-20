/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void solve(TreeNode* root,vector<int> &a)
    {
        if(!root)
            return;
        solve(root->left,a);
        a.push_back(root->val);
        solve(root->right,a);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> a;
        solve(root,a);
        return a;
    }
};