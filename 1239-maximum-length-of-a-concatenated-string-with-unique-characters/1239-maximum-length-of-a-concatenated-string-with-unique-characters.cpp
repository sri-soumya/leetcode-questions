class Solution {
public:
    
    int freq(vector<int> &a)
    {
        int c=0;
        for(auto x:a)
        {
            c+=x;
        }
        return c;
    }
    
    int add(vector<int> &a,string &s)
    {
        unordered_map<int,int> mp;
        for(auto x:s)
        {
            if(a[x-'a']>0||mp.count(x))
                return -1;
            mp[x]++;
        }
        
        for(auto x:s)
        {
            a[x-'a']++;
        }
        
        return 1;
    }
    
    void sub(vector<int> &a,string &s)
    {
        for(auto x:s)
        {
            a[x-'a']--;
        }
    }
    
    
    int solve(int i,vector<string> &arr,vector<int> &a)
    {
        
        if(i<0)
        {
            return freq(a);
        }
        
        int c1=0,c2=0;
        
        c1=solve(i-1,arr,a);
        
        int f=add(a,arr[i]);
        if(f==-1)
            return c1;
        c2=solve(i-1,arr,a);
        sub(a,arr[i]);
        
        return max(c1,c2);
        
    }
    
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        vector<int> a(26);
        return solve(n-1,arr,a);
    }
};