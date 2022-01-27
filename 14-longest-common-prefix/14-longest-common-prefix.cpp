class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        
        //sort(s.begin(),s.end());
        
        string a=s[0];
        string x="";
        for(int i=0;i<a.length();i++)
        {
            for(int j=0;j<s.size();j++)
            {
                if(a[i]!=s[j][i])
                    return x;
            }
            
            x+=a[i];
        }
        
        return x;
        
    }
};