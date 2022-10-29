class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        vector<vector<int>> a;
        
        for(int i=0;i<n;i++)
        {
            a.push_back({growTime[i],plantTime[i]});
        }
        
        sort(a.begin(),a.end());
        int m=0;
        
        for(auto x:a)
        {
            m=max(m,x[0])+x[1];
        }
        
        return m;
    }
};