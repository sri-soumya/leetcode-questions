class Solution {
public:
    string removeDuplicateLetters(string s) {
     
        int n=s.length();
        vector<int> lastind(26,0),v(26,0);
        stack<char> st;
        string ans="";
        
        for(int i=0;i<n;i++)
        {
            lastind[s[i]-'a']=i;
        }
        for(int i=0;i<n;i++)
        {
            int in=s[i]-'a';
            if(v[in])
                continue;
            while(st.size()&&st.top()>s[i]&&lastind[st.top()-'a']>i)
            {
                v[st.top()-'a']=0;
                st.pop();
            }
            st.push(s[i]);
            v[in]=1;    
        }
        
        while(st.size())
        {
            ans=st.top()+ans;
            st.pop();
        }
        
        return ans;
    }
};