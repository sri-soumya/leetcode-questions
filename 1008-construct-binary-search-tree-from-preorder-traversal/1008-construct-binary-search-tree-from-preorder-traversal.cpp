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
    
    TreeNode* solve(vector<int> nums,int in,int n)
    {
        if(in>n)
            return NULL;
        TreeNode *t=new TreeNode(nums[in]);
        int i;
        for(i=in;i<=n;i++)
            if(nums[i]>nums[in])
                break;
        t->left=solve(nums,in+1,i-1);
        t->right=solve(nums,i,n);
        return t;
    }
    
    TreeNode* bstFromPreorder(vector<int>& nums) {
        
        return solve(nums,0,nums.size()-1);
        
    }
};