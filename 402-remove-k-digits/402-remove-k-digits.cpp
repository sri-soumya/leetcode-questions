class Solution {
public:
    string removeKdigits(string num, int k) {
       
        int n=num.length();
        if(k>=n)
            return "0";
        stack<char> s;
        k=n-k;
        
        for(int i=0;i<n;i++)
        {
            while(s.size()&&(s.size()+n-1-i)>=k&&num[i]<s.top())
                s.pop();
            s.push(num[i]);
        }
        while(s.size()>k)
            s.pop();
        string ans="";
        while(s.size())
        {
            ans=s.top()+ans;
            s.pop();
        }
        
        int i=0;
        while(i<ans.size()&&ans[i]=='0')
        {
            i++;
        }
        if(i==ans.size())
            return "0";
        return ans.substr(i);
    }
};