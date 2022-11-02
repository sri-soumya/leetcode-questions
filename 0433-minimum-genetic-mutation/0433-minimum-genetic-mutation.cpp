class Solution {
public:
    
    int check(string &a,string &b)
    {
        int c=0;
        for(int i=0;i<8;i++)
        {
            if(a[i]!=b[i])
                c++;
        }
        
        return c==1;
    }
    
    void solve(string a,string &b,vector<string> &bank,int c,int &ans,map<string,int> &mp)
    {
        if(a==b)
        {
            ans=min(ans,c);
            return;
        }
        //cout<<a<<endl;
        for(auto x:bank)
        {
            if(check(x,a)&&!mp.count(x))
            {
                mp[x]++;
                solve(x,b,bank,c+1,ans,mp);
                mp.erase(x);
            }
        }
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        int ans=1e7;
        //vector<bool> v(bank.size(),0);
        map<string,int> mp;
        solve(start,end,bank,0,ans,mp);
        
        if(ans==1e7)
            return -1;
        return ans;
    }
};