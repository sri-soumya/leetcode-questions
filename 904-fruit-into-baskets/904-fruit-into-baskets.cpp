class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n=fruits.size(),l=0,r=0,ans=0;
        
        unordered_map<int,int> mp;
        
        while(l<n)
        {
            while(mp.size()<=2&&r<n)
            {
                mp[fruits[r]]++;
                r++;
                if(mp.size()>2)
                {
                    r--;
                    mp.erase(fruits[r]);
                    break;
                }
            }
            
            ans=max(ans,r-l);
            mp[fruits[l]]--;
            if(mp[fruits[l]]==0)
                mp.erase(fruits[l]);
            l++;
        }
        
        return ans;
    }
};