class Solution {
public:
    
    int solve(vector<int> &arr,int i,int j,map<int,int> &mp)
    {
        int x=arr[i]+arr[j];
        if(!mp.count(x))
            return 0;
        int in=mp[x];
        return solve(arr,j,in,mp)+1;
    }
    
    int lenLongestFibSubseq(vector<int>& arr) {
        
        map<int,int> mp;
        int n=arr.size(),ans=0;
        
        for(int i=0;i<n;i++)
            mp[arr[i]]=i;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                ans=max(ans,solve(arr,i,j,mp)+2);
            }
        }
        if(ans<3)
            ans=0;
        return ans;
    }
};