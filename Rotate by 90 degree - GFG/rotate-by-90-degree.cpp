// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


 // } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int> >& a)
{
    // Your code goes here
    int n=a.size();
    int t=0,l=0,r=n-1,b=n-1;
    
    while(l<r)
    {
        for(int i=0;i<r-l;i++)
        {
            int x=a[t][l+i];
            a[t][l+i]=a[t+i][r];
            a[t+i][r]=a[b][r-i];
            a[b][r-i]=a[b-i][l];
            a[b-i][l]=x;
        }
        
        t++;l++;r--;b--;
    }
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}

  // } Driver Code Ends