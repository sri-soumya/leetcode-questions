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

// class iter{
//     public:
//     stack<TreeNode*> *s;
//     iter(TreeNode* root)
//     {
//         s=new stack<TreeNode*>();
//         auto t=root;
//         while(t)
//         {
//             s->push(t);
//             t=t->left;
//         }
        
//     }
    
    
// };

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(!root)
            return root;
        
        root->left=increasingBST(root->left);
        root->right=increasingBST(root->right);
        
        auto t=root->left;
        
        while(t&&t->right)
            t=t->right;
        
        if(!t)
            return root;
        
        auto tt=root->left;
        root->left=NULL;
        t->right=root;
        
        return tt;
        
        
    }
};