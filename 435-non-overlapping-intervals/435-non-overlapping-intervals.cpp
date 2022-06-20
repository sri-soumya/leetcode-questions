class Solution {
public:
    
    static bool compare(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& a) {
     
        int n=a.size();
        sort(a.begin(),a.end(),compare);
        int c=0;
        //vector<vector<int>> p(1,a[0]);
        vector<int> p=a[0];
        for(int i=1;i<n;i++)
        {
            if(a[i][0]>=p[1])
            {
                p=a[i];
            }
            else
                c++;
        }
        
        return c;
    }
};