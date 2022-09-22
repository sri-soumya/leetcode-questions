class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        s+=" ";
        string z="";
        for(auto x:s)
        {
            if(x==' ')
            {
                ans+=z+" ";
                z="";
            }
            else
            {
                z=x+z;
            }
        }
        
        return ans.substr(0,ans.size()-1);
    }
};