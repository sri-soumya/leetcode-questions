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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> a;
        TreeNode* cur=root;
        
        while(cur)
        {
            if(!cur->left)
            {
                a.push_back(cur->val);
                cur=cur->right;
            }
            else
            {
                TreeNode* t=cur->left;
                while(t->right&&t->right!=cur)
                    t=t->right;
                if(!t->right)
                {
                    t->right=cur;
                    cur=cur->left;
                }
                else
                {
                    a.push_back(cur->val);
                    t->right=NULL;
                    cur=cur->right;
                }
            }
        }
        
        return a;
    }
};