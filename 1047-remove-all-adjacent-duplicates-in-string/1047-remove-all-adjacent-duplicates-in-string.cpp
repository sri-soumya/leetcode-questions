class Solution {
public:
    string removeDuplicates(string a) {
        stack<char> s;
        int n=a.size();
        
        for(int i=0;i<n;i++)
        {
            if(s.size()&&s.top()==a[i])
                s.pop();
            else
                s.push(a[i]);
        }
        
        string ans="";
        
        while(s.size())
        {
            ans+=s.top();
            s.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};