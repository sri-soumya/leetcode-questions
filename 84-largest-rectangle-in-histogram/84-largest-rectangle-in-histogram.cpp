class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        stack<int> x;
        int n=heights.size();
        for(int i=0;i<n;i++)
        {
            while(x.size()&&heights[x.top()]>=heights[i])
            {
                int j=x.top();
                x.pop();
                int pa=(x.size())?heights[j]*(i-x.top()-1):heights[j]*i;
                
                ans=max(ans,pa);
            }
            x.push(i);
            
        }
        
        while(x.size())
        {
            int j=x.top();
            x.pop();
            int pa=(x.size())?heights[j]*(n-x.top()-1):heights[j]*n;
            
            ans=max(ans,pa);
        }
        
        return ans;
    }
};