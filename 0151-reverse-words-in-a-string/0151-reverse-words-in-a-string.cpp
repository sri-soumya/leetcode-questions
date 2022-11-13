class Solution {
public:
    string reverseWords(string s) {
        
        string t="",ans="";
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=' ')
                t+=s[i];
            else
            {
                if(t.length()==0)
                    continue;
                if(ans.length()>0)
                    ans=t+" "+ans;
                else
                    ans=t+ans;
                t="";
            }
        }
        if(t.length()&&ans.length())
            ans=t+" "+ans;
        else if(t.length()&&!ans.length())
            ans=t+ans;
        
        return ans;
        
    }
};