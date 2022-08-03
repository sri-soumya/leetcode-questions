class Solution {
public:
    string removeKdigits(string num, int k) {
       
        int n=num.length();
        if(k>=n)
            return "0";
        stack<char> s;
        
        for(int i=0;i<n;i++)
        {
            char c=num[i];
            while(s.size()&&k&&num[i]<s.top())
            {
                k--;
                s.pop();
            }
            s.push(num[i]);
        }
        
        while(s.size()&&k)
        {
            k--;
            s.pop();
        }
        
        string ans="";
        
        while(s.size())
        {
            ans+=s.top();
            s.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        int in=0;
        while(in<ans.size()&&ans[in]=='0')
            in++;
        
        if(in==ans.size())
            return "0";
        
        
        return ans.substr(in);
        return ans;
        
    }
};