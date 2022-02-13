class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        for(int i=0;i<s.length();i++)
        {
            char c=s[i];
            if(c=='('||c=='['||c=='{')
                a.push(c);
            else
            {
                if(a.size()&&((a.top()=='('&&c==')')||(a.top()=='['&&c==']')||(a.top()=='{'&&c=='}')))
                    a.pop();
                else
                    return false;
            }
        }
        
        return !a.size();
    }
};