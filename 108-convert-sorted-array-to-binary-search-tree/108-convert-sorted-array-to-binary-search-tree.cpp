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
    
    TreeNode* solve(int i,int j,vector<int> &nums)
    {
        if(i>j)
            return NULL;
        int m=(i+j)/2;
        TreeNode* t=new TreeNode(nums[m]);
        t->left=solve(i,m-1,nums);
        t->right=solve(m+1,j,nums);
        
        return t;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return solve(0,n-1,nums);
    }
};