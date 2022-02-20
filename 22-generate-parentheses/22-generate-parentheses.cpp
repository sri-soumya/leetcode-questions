class Solution {
public:
    
    vector<string> solve(int n)
    {
        vector<string> a;
        if(n==1)
        {
            a.push_back("()");
            return a;
        }
        
        vector<string> b=solve(n-1);
        set<string> x;
        for(int i=0;i<b.size();i++)
        {
            string s=b[i];
            x.insert("()"+s);
            x.insert(s+"()");
            for(int j=0;j<s.length();j++)
            {
                if(s[j]==')')
                    continue;
                string z=(j>0)?s.substr(0,j):"";
                
                 z+="("+s.substr(j);
               
                for(int k=j;k<z.length();k++)
                {
                    
                    if(z[k]==')')
                    {
                        x.insert(z.substr(0,k+1)+")"+z.substr(k+1));
                    }
                }
            }
        }
        
        for(auto i:x)
            a.push_back(i);
        return a;
            
    }
    
    vector<string> generateParenthesis(int n) {
        return solve(n);
    }
};