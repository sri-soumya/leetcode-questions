class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& w) {
        
        int n=s.length(),m=w.size();
        int c=0;
        unordered_map<char,vector<int>> mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]].push_back(i);
        }
        
        for(auto x:w)
        {
            //cout<<x<<endl;
            int k=-1;
            bool f=1;
            for(auto j:x)
            {
                if(mp.count(j)==0)
                {
                    f=0;
                    break;
                }
                int in=lower_bound(mp[j].begin(),mp[j].end(),k+1)-mp[j].begin();
                if(in==mp[j].size())
                {
                    f=0;
                    break;
                }
                //cout<<k+1<<" "<<in<<endl;
                k=mp[j][in];
            }
            
            if(f)
                c++;
        }
        
        return c;
        
    }
};