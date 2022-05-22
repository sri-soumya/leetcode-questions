class Solution {
public:
    
    int solve(vector<int> a)
    {
        int n=a.size(),l=0,u=n-1;
        int s=0;
        while(l<=u)
        {
            int m=(l+u)/2;
            if(a[0]>a[m])
            {
                s=m;
                u=m-1;
            }
            else
                l=m+1;
        }
        
        return a[s];
    }
    
    int findMin(vector<int>& nums) {
       return solve(nums);
    }
};