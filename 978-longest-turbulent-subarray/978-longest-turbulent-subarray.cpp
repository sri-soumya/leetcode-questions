class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        int n=arr.size(),ans=1;
        
        for(int i=0;i<n;)
        {
            int c=-2,j=i;
            while(j<n-1)
            {
                int x;
                if(arr[j+1]==arr[j])
                    x=-1;
                else
                    x=arr[j+1]<arr[j];
                if((c==-2||c!=x)&&x!=-1)
                {
                    c=x;
                    j++;
                    continue;
                }
                else
                    break;
            }
            ans=max(ans,j-i+1);
            i=max(j,i+1);
        }
        
        return ans;
    }
};