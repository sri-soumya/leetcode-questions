class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int n=arr.size();
        map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        
        vector<int> b;
        
        for(auto x:mp)
        {
            b.push_back(x.second);
        }
        
        sort(b.begin(),b.end(),greater<>());
        
        int c=0,s=0;
        
        for(auto x:b)
        {
            if(s>=n/2)
                break;
            s+=x;
            c++;
        }
        
        return c;
    }
};