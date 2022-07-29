class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
     
        int n=heights.size(),ans=0;
        stack<int> s;
        
        for(int i=0;i<n;i++)
        {
            while(s.size()&&heights[s.top()]>=heights[i])
            {
                int in=s.top();
                s.pop();
                int w=i-(s.size()?s.top()+1:0);
                ans=max(ans,w*heights[in]);
            }
            
            s.push(i);
        }
        
        while(s.size())
        {
            int in=s.top();
            s.pop();
            int w=n-(s.size()?s.top()+1:0);
            ans=max(ans,w*heights[in]);
        }
        
        return ans;
    }
};