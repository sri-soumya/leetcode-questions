class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        
        while(s.length()%k>0)
        {
            //s+=to_string(fill);
            s+=fill;
        }
        vector<string> a;
        for(int i=0;i<s.length();i+=k)
            a.push_back(s.substr(i,k));
        
        return a;
        
    }
};