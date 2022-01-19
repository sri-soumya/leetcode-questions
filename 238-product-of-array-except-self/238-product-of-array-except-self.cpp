class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size();
        int l[n];
        int r[n];
        
        l[0]=nums[0];
        r[n-1]=nums[n-1];
        
        for(int i=1;i<n;i++)
        {
            l[i]=l[i-1]*nums[i];
        }
        
        for(int i=n-2;i>=0;i--)
            r[i]=r[i+1]*nums[i];
        
        vector<int> a;
        
        for(int i=0;i<n;i++)
        {
            int x=((i-1>=0)?l[i-1]:1)*((i+1<n)?r[i+1]:1);
            a.push_back(x);
        }
        
        return a;
        
        
    }
};