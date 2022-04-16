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
    
    int solve(TreeNode* root,int k,int& c)
    {
        if(!root)
            return -1;
        int a=solve(root->left,k,c);
        c++;
        if(c==k)
            return root->val;
        else if(c<k)
            return solve(root->right,k,c);
        return a;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int c=0;
        return solve(root,k,c);
    }
};