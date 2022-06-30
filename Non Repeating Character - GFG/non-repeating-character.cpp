// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string s)
    {
       //Your code here
       int n=s.length();
       vector<int> a(26,-1);
       
       for(int i=0;i<n;i++)
       {
           if(a[s[i]-'a']==-1)
                a[s[i]-'a']=i;
            else
                a[s[i]-'a']=-2;
       }
       
       int in=1e7;
       
       for(int i=0;i<26;i++)
       {
           if(a[i]==-1||a[i]==-2)
                continue;
            in=min(in,a[i]);
       }
       
       if(in==1e7)
        return '$';
        
        return s[in];
       
    }

};

// { Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}
  // } Driver Code Ends