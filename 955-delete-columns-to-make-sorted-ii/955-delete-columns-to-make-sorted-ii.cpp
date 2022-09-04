class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int ans=0,n=strs.size(),m=strs[0].size();
        
        map<int,int> mp;
        
        for(int i=0;i<n;)
        {
            bool f=0;
            for(int j=i+1;j<n;j++)
            {
                for(int k=0;k<m;k++)
                {
                    if(mp.count(k)||strs[i][k]==strs[j][k])
                        continue;
                    if(strs[i][k]<strs[j][k])
                        break;
                    mp[k]++;
                    f=true;
                    break;
                }
                if(f)
                    break;
            }
            if(f)
                i=0;
            else
                i++;
        }
        
        return mp.size();
        
    }
};