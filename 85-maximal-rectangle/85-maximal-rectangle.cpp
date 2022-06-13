class Solution {
public:
    
    int solve(vector<int>& a) {
        
        int n=a.size();
        vector<int> l(n,0),r(n,0);
        stack<int> s;
        
        for(int i=0;i<n;i++)
        {
            while(s.size()&&a[s.top()]>=a[i])
            {
                s.pop();
            }
            if(s.size())
                l[i]=s.top()+1;
            else
                l[i]=0;
            s.push(i);
        }
        
        while(s.size())
        {
            s.pop();
        }
        
        for(int i=n-1;i>=0;i--)
        {
            while(s.size()&&a[s.top()]>=a[i])
            {
                s.pop();
            }
            if(s.size())
                r[i]=s.top()-1;
            else
                r[i]=n-1;
            s.push(i);
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            ans=max(ans,a[i]*abs(r[i]-l[i]+1));
        }
        
        return ans;
        
    }
    
    int maximalRectangle(vector<vector<char>>& a) {
        
        int ans=0,n=a.size(),m=a[0].size();
        vector<int> x(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='1')
                    x[j]++;
                else
                    x[j]=0;
            }
            
            ans=max(ans,solve(x));
        }
        return ans;
    }
};