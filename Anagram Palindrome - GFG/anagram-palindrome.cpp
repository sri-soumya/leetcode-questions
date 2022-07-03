// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int isPossible (string s);

int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		if (isPossible (s))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int isPossible (string s)
{
    // your code here
    int n=s.length();
    map<int,int> mp;
    
    for(int i=0;i<n;i++)
        mp[s[i]]++;
        
    int c=0;
    
    for(auto x:mp)
    {
        c+=x.second%2;
    }
    
    if(n%2==0&&c)
        return 0;
    if(n%2&&c>1)
        return 0;
    return 1;
}