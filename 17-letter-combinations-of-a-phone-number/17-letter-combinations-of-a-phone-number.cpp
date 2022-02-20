class Solution {
public:
    
    vector<string> solve(string digits,vector<string> x,vector <string> a)
    {
        vector<string> ans;
        int n=digits.length();
        if(!n)
            return a;
        
        if(!a.size())
            a.push_back("");
        int in=digits[0]-'0';
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<x[in].length();j++)
                ans.push_back(a[i]+x[in].substr(j,1));
        }
        
        return solve(digits.substr(1),x,ans);
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        vector<string> x={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        return solve(digits,x,ans);
    }
};