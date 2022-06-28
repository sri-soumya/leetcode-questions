class Solution {
public:
    int maxSubArray(vector<int>& a) {
        
        int n=a.size(),s=0,m=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            s+=a[i];
            m=max(m,s);
            if(s<0)
                s=0;
        }
        return m;
    }
};