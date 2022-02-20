class Solution {
public:
    
    static bool compare(vector<int> a,vector<int> b)
    {
        if(a[0]!=b[0])
            return a[0]<b[0];
        return a[1]>b[1];
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(),compare);
        vector<int> x=intervals[0];
        int c=0,n=intervals.size();
        
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]>=x[0]&&intervals[i][1]<=x[1])
                c++;
            else
                x=intervals[i];
        }
        
        return n-c;
    }
};