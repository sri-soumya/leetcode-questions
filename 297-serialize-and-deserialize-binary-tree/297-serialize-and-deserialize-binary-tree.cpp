/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string a="";
        if(!root)
            return a;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size())
        {
            auto t=q.front();
            q.pop();
            
            if(t)
            {
                a+=to_string(t->val)+" ";
                q.push(t->left);
                q.push(t->right);
            }
            if(!t)
                a+="-10000 ";
            
        }
        
        return a;
            
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string d) {
        //cout<<d<<endl;
        int n=d.length();
        if(!n)
            return NULL;
        int i=0;
        string s="";
        while(i<n&&d[i]!=' ')
        {
            s+=(d[i]);
            i++;
        }
        i++;
        TreeNode *root=new TreeNode(stoi(s));
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size())
        {
            auto t=q.front();
            q.pop();
            string c1="",c2="";
            while(i<n&&d[i]!=' ')
            {
                c1+=(d[i]);
                i++;
            }
            i++;
            while(i<n&&d[i]!=' ')
            {
                c2+=(d[i]);
                i++;
            }
            i++;
            //cout<<t->val<<" "<<c1<<" "<<c2<<endl;
            int c1i=stoi(c1),c2i=stoi(c2);
            if(c1i!=-10000)
            {
                TreeNode* l=new TreeNode(c1i);
                t->left=l;
                q.push(l);
            }
            
            if(c2i!=-10000)
            {
                TreeNode* r=new TreeNode(c2i);
                t->right=r;
                q.push(r);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));