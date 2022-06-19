class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& a, string s) {
     
        vector<vector<string>> b;
        sort(a.begin(),a.end());
        for(int i=0;i<a.size();i++)
            cout<<a[i]<<" ";
        cout<<endl;
        string k="";
        
        for(int i=0;i<s.length();i++)
        {
            k+=s[i];
            
            int in=lower_bound(a.begin(),a.end(),k)-a.begin();
            
            vector<string> c;
            for(int j=in;j<in+3;j++)
            {
                if(j>=a.size())
                    break;
                if(a[j].find(k)==0)
                    c.push_back(a[j]);
            }
            b.push_back(c);
            
        }
        
        return b;
        
    }
};