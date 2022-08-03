class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> ans(n,INT_MAX);
        stack<int> s;
        
        for(int x=0;x<2;x++)
        {
            for(int i=n-1;i>=0;i--)
            {
                if(ans[i]!=INT_MAX)
                    continue;
                
                while(s.size()&&nums[i]>=s.top())
                    s.pop();
                
                if(s.size())
                    ans[i]=s.top();
                s.push(nums[i]);
            }
        }
        
        for(int i=0;i<n;i++)
            if(ans[i]==INT_MAX)
                ans[i]=-1;
        
        return ans;
    }
};