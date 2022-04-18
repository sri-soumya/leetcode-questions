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
    
    int solve(TreeNode* root, int k,int &c)
    {
        if(!root)
            return -1;
        
        int a=solve(root->left,k,c);
        if(c>=k)
            return a;
        c++;
        if(c==k)
            return root->val;
        return solve(root->right,k,c);
    }
    int kthSmallest(TreeNode* root, int k) {
        int c=0;
        
        return solve(root,k,c);
    }
};