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
    
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int a,int b,int c,int d)
    {
        if(a>b||c>d)
            return NULL;
        
        TreeNode* t=new TreeNode(postorder[d]);
        int i;
        for(i=a;i<=b;i++)
            if(inorder[i]==postorder[d])
                break;
        int l=i-a;
        t->left=solve(inorder,postorder,a,a+l-1,c,c+l-1);
        t->right=solve(inorder,postorder,i+1,b,c+l,d-1);
        
        return t;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        return solve(inorder,postorder,0,inorder.size()-1,0,inorder.size()-1);
        
    }
};