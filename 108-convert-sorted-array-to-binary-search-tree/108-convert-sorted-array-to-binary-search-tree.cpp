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
    
    TreeNode* solve(vector<int> nums,int i,int n)
    {
        if(i>n)
            return NULL;
        
        int m=(i+n)/2;
        TreeNode* t=new TreeNode(nums[m]);
        t->left=solve(nums,i,m-1);
        t->right=solve(nums,m+1,n);
        return t;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return solve(nums,0,nums.size()-1);
        
    }
};