class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        vector<int> b;
        b.push_back(a[0]);
        int n=a.size();
        for(int i=1;i<n;i++)
        {
            if(a[i]>b.back())
                b.push_back(a[i]);
            else
            {
                int x=lower_bound(b.begin(),b.end(),a[i])-b.begin();
                b[x]=a[i];
            }
        }
        
        return b.size();
    }
};