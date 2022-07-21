class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> trustedBy(n+1,0);
        
        for(auto x:trust)
        {
            trustedBy[x[0]]--;
            trustedBy[x[1]]++;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(trustedBy[i]==n-1)
                return i;
        }
        
        return -1;
    }
};