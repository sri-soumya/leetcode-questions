class Solution {
public:
    
    static bool compare(vector<int> &a,vector<int> &b)
    {
        return a[1]>b[1];
    }
    
    int maximumUnits(vector<vector<int>>& a, int t) {
        
        sort(a.begin(),a.end(),compare);
        
        int s=0,n=a.size();
        
        for(int i=0;i<n;i++)
        {
            s+=min(t,a[i][0])*a[i][1];
            t-=min(t,a[i][0]);
            if(t<=0)
                break;
        }
        
        return s;
        
    }
};