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
    bool isCousins(TreeNode* root, int x, int y) {
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(q.size()&&q.front())
        {
            int c=0;
            while(q.front())
            {
                TreeNode* t=q.front();
                q.pop();
                if(t->val==x||t->val==y)
                    c++;
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
                if(!t->left||!t->right)
                    continue;
                if((t->left->val==x&&t->right->val==y)||(t->left->val==y&&t->right->val==x))
                    return 0;
            }
            q.pop();
            q.push(NULL);
            if(c==2)
                return true;
            
        }
        
        return 0;
        
    }
};