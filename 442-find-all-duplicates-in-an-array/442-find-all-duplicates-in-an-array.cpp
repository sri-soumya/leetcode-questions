class Solution {
public:
    vector<int> findDuplicates(vector<int>& a) {
        
        int n=a.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            int x=abs(a[i]);
            if(a[x-1]<0)
                ans.push_back(x);
            else
                a[x-1]*=-1;
        }
        
        return ans;
        
    }
};