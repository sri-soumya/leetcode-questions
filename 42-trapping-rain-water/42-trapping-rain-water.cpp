class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        vector<int> maxr(n,0);
        vector<int> maxl(n,0);
        maxr[n-1]=height[n-1];
        maxl[0]=height[0];
        for(int i=n-2;i>=0;i--)
        {
            maxr[i]=max(maxr[i+1],height[i]);
            maxl[n-i-1]=max(maxl[n-i-2],height[n-i-1]);
        }
        int s=0;
        for(int i=0;i<n;i++)
        {
            s+=min(maxl[i],maxr[i])-height[i];
        }
        
        return s;
        
    }
};