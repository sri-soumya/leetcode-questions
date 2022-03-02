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
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int a,int b,int c,int d)
    {
        
        if(a>b||c>d)
            return NULL;
        
        //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        
        TreeNode* t=new TreeNode(preorder[a]);
        int i=c;
        for(i=c;i<=d;i++)
            if(inorder[i]==preorder[a])
                break;
        int l=i-c;
        t->left=solve(preorder,inorder,a+1,a+l,c,i-1);
        t->right=solve(preorder,inorder,a+l+1,b,i+1,d);
        
        return t;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder,inorder,0,preorder.size()-1,0,preorder.size()-1);
    }
};