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
    
    int height(TreeNode* root)
    {
        if(!root)
            return 0;
        
        return max(height(root->left),height(root->right))+1;
    }
    
    int solve(TreeNode* root)
    {
        
        if(!root)
            return 0;
        
        if(!root->left&&!root->right)
            return 0;
        
        int x=solve(root->left)+solve(root->right);
        
        if((root->left&&root->left->val==0)||(root->right&&root->right->val==0))
        {
            root->val=2;
            return x+1;
        }
        
        if((root->left&&root->left->val==2)||(root->right&&root->right->val==2))
        {
            //root->val=2;
            root->val=1;
            return x;
        }
        
        //root->val=1;
        
        return x;
    }
    
    int minCameraCover(TreeNode* root) {
        
       int c=solve(root);
        if(root->val==0)
            c++;
        
       return c;
        
    }
};