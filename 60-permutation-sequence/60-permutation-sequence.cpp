class Solution {
public:
    string getPermutation(int n, int k) {
        
        vector<int> a;
        vector<int> c;
        string b="";
        int p=1;
        for(int i=1;i<=n;i++)
        {
            a.push_back(p);
            p*=i;
            //b+=to_string(i);
            c.push_back(i);
        }
        k--;
        for(int i=0;i<n;i++)
        {
            int m=k/a[n-i-1];
            k%=a[n-i-1];
            b+=to_string(c[m]);
            c.erase(c.begin()+m);
        }
        return b;
    }
};