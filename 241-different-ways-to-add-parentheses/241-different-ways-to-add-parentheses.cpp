class Solution {
public:
    
    
    void combine(vector<int> &a,vector<int> b,vector<int> c,int k)
    {
        int n=b.size(),m=c.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x=0;
                if(k=='+')
                    x=b[i]+c[j];
                else if(k=='-')
                    x=b[i]-c[j];
                else
                    x=b[i]*c[j];
                a.push_back(x);
            }
        }
    }
    
    vector<int> solve(string &s,int i,int j)
    {
        vector<int> a;
        if(i>j)
            return a;
        
        int c=0;
        
        for(int k=i;k<=j;k++)
        {
            if(s[k]>='0'&&s[k]<='9')
                continue;
            c++;
            vector<int> b,c;
            b=solve(s,i,k-1);
            c=solve(s,k+1,j);
            combine(a,b,c,s[k]);
        }
        
        if(!c)
            a.push_back(stoi(s.substr(i,j-i+1)));
        
        return a;
    }
        
    
    vector<int> diffWaysToCompute(string s) {
        
        int n=s.length();
        
        return solve(s,0,n-1);
        
    }
};