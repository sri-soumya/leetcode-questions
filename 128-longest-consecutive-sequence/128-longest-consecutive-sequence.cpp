class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        
        int n=a.size();
        unordered_map<int,int> mp;
        
        int ans=0;
        
        for(auto x:a)
            mp[x]++;
        
        for(int i=0;i<n;i++)
        {
            int c=0;
            if(mp.count(a[i]-1))
                continue;
            for(int j=a[i];;j++)
            {
                if(mp.count(j))
                {
                    c++;
                    //mp[j]--;
                }
                else
                    break;
            }
            
            ans=max(ans,c);
        }
        return ans;
    }
};