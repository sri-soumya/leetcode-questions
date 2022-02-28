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
        
        vector<vector<int>> a;
        int c=0;
        deque<TreeNode*> q;
        if(!root)
            return a;
        q.push_back(root);
        
        while(q.size())
        {
            c++;
            int x=q.size();
            vector<int> b;
            for(int i=0;i<x;i++)
            {
                if(c%2)
                {
                    TreeNode* t=q.front();
                    q.pop_front();
                    b.push_back(t->val);
                    if(t->left)
                        q.push_back(t->left);
                    if(t->right)
                        q.push_back(t->right);
                }
                else
                {
                    TreeNode* t=q.back();
                    q.pop_back();
                    b.push_back(t->val);
                    if(t->right)
                        q.push_front(t->right);
                    if(t->left)
                        q.push_front(t->left);
                }
            }
            
            a.push_back(b);
        }
        return a;
    }
};