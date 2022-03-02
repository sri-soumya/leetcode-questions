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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        int c=1;
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(!root)
            return ans;
        q.push(root);
        
        while(q.size())
        {
            int x=q.size();
            vector<int> a(x,0);
            for(int i=0;i<x;i++)
            {
                TreeNode* t=q.front();
                q.pop();
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
                if(c)
                    a[i]=t->val;
                else
                    a[x-i-1]=t->val;
            }
            
            ans.push_back(a);
            c=c^1;
        }
        
        return ans;
        
        
    }
};