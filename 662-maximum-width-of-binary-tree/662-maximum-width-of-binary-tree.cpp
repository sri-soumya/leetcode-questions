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
    int widthOfBinaryTree(TreeNode* root) {
        
        unsigned long long int ans=0;
        if(!root)
            return 0;
        queue<pair<TreeNode*,unsigned long long int>> q;
        q.push({root,0});
        
        while(q.size())
        {
            TreeNode* t=q.front().first;
            unsigned long long l=q.front().second;
            q.pop();
            unsigned long long x=q.size(),c=l;
            if(t->left)
                q.push({t->left,l*2+1});
            if(t->right)
                q.push({t->right,l*2+2});
            while(x)
            {
                x--;
                //c++;
                TreeNode* tt=q.front().first;
                c=q.front().second;
                q.pop();
                if(tt->left)
                    q.push({tt->left,c*2+1});
                if(tt->right)
                    q.push({tt->right,c*2+2});
            }
            
            ans=max(ans,c-l+1);
        }
        
        return ans;
        
        //return ans;
        
    }
};