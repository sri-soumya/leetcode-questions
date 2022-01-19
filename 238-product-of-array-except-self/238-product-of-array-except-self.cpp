class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int> a;
        a.push_back(1);
        for(int i=1;i<n;i++)
            a.push_back(a[i-1]*nums[i-1]);
        
        int t=1;
        for(int i=n-2;i>=0;i--)
        {
            t*=nums[i+1];
            a[i]*=t;
        }
        
        return a;
        
        
    }
};