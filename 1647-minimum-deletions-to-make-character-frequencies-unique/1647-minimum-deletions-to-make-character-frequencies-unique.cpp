class Solution {
public:
    int minDeletions(string s) {
        
        map<int,int> mp;
        vector<int> a(26,0);
        int n=s.length(),c=0;
        
        for(int i=0;i<n;i++)
        {
            //mp[s[i]-'a']++;
            a[s[i]-'a']++;
        }
        
        for(int i=0;i<26;i++)
        {
            if(a[i]==0)
                continue;
            mp[a[i]]++;
            if(mp[a[i]]==1)
                continue;
            int j;
            for(j=a[i];j>=0;j--)
            {
                if(!mp.count(j))
                    break;
                
            }
            
            mp[a[i]]--;
            c+=a[i]-j;
            if(j)
                mp[j]++;
        }
        
//         for(int i=0;i<26;i++)
//         {
//             if(a[i]==0||mp[a[i]]==1)
//                 continue;
            
//             int j;
//             for(j=a[i];j>=0;j--)
//             {
//                 if(!mp.count(j))
//                     break;
                
//             }
            
//             mp[a[i]]--;
//             c+=a[i]-j;
//             if(j)
//                 mp[j]++;
//         }
        
        return c;
    }
};