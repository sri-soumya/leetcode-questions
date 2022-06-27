class Solution {
public:
    vector<int> runningSum(vector<int>& a) {
        int n=a.size();
        vector<int> s(n,0);
        s[0]=a[0];
        for(int i=1;i<n;i++)
            s[i]=s[i-1]+a[i];
        
        return s;
    }
};