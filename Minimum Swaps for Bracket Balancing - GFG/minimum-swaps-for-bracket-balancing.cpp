// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string s){
        // code here 
        int n=s.length();
        int c=0;
        int x=0;
        int p=0;
        vector<int> a;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='[')
                a.push_back(i);
        }
        
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='[')
            {
                x++;
                p++;
            }
            else
                x--;
            if(x<0)
            {
                c+=abs(i-a[p]);
                swap(s[i],s[a[p]]);
                p++;
                x=1;
            }
        }
        
        return c;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends