class Solution {
public:
    
    void solve(string s,int i,int n,int k,vector<int> &ans)
    {
        if(i>=n)
        {
            ans.push_back(stoi(s));
            return;
        }
        if(i==0)
        {
            for(int j=1;j<=9;j++)
            {
                s[0]='0'+j;
                solve(s,i+1,n,k,ans);
            }
        }
        else
        {
            int x=s[i-1]-k,y=s[i-1]+k;
            if(x>='0'&&x<='9')
            {
                s[i]=x;
                solve(s,i+1,n,k,ans);
            }

            if(y>='0'&&y<='9'&&k)
            {
                s[i]=y;
                solve(s,i+1,n,k,ans);
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        string s="";
        for(int i=0;i<n;i++)
            s+=' ';
        
        vector<int> ans;
        solve(s,0,n,k,ans);
        return ans;
    }
};