class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        vector<int> ans;
        
        for(int i=1;i<=9;i++)
        {
            int k=i;
            for(int j=i+1;j<=9;j++)
            {
                k=k*10+j;
                if(k>=low&&k<=high)
                    ans.push_back(k);
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }
};