class Node
{
    Node* a[2];
    
    public:
    
    bool containsNode(int x)
    {
        return a[x]!=NULL;
    }
    
    void addNode(int x,Node* t)
    {
        a[x]=t;
    }
    
    Node* nextNode(int x)
    {
        return a[x];
    }
};


class Trie
{
    Node* root;
    
    public:
    
    Trie()
    {
        root=new Node();
    }
    
    void insert(int a)
    {
        Node* t=root;
        for(int i=31;i>=0;i--)
        {
            int x=(a>>i)&1;
            if(!t->containsNode(x))
                t->addNode(x,new Node());
            t=t->nextNode(x);
        }
        
    }
    
    int maxXOR(int a)
    {
        Node *t=root;
        int n=0;
        for(int i=31;i>=0;i--)
        {
            int x=!((a>>i)&1);
            if(!t->containsNode(x))
            {
                t=t->nextNode(!x);
            }
            else
            {
                n=n|(1<<i);
                t=t->nextNode(x);
            }
        }
        
        return n;
    }
};

class Solution {
public:
    
    static bool compare(pair<int,vector<int>> &a,pair<int,vector<int>> &b)
    {
        return a.second[1]<b.second[1];
    }

    
    vector<int> maximizeXor(vector<int>& a, vector<vector<int>>& q) {
     
        int n=a.size(),m=q.size();
        vector<pair<int,vector<int>>> b;
        for(int i=0;i<m;i++)
            b.push_back({i,q[i]});
        
        sort(b.begin(),b.end(),compare);
        sort(a.begin(),a.end());
        vector<int> ans(m,-1);
        Trie ob;
        int k=0;
        
        for(int i=0;i<m;i++)
        {
            //cout<<q[i][1]<<" ";
            for(;k<n&&a[k]<=b[i].second[1];k++)
                ob.insert(a[k]);
            if(!k)
                ans[b[i].first];
            else
                ans[b[i].first]=(ob.maxXOR(b[i].second[0]));
        }
        //cout<<endl;
        return ans;
        
    }
};