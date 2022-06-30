class Solution {
public:
    
    int solve(vector<int> &a,int x)
    {
        int n=a.size(),s=0;
        
        for(int i=0;i<n;i++)
        {
            s+=abs(a[i]-x);
        }
        
        return s;
    }
    
    int minMoves2(vector<int>& a) {
        
        sort(a.begin(),a.end());
        
        int c1=INT_MAX,n=a.size();
        
        c1=solve(a,a[n/2]);
       
        return c1;
        
    }
};