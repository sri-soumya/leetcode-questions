class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string l=to_string(low),h=to_string(high);
        //cout<<l<<endl;
        string s=l.substr(0,1);
        //cout<<s<<endl;
        while(s.length()<l.length())
        {
            int n=s.length();
            int c=s[n-1]-'0';
            
            if(c<9)
            {
                
                s+=to_string((c+1));
                //cout<<s<<endl;
            }
            
            else
            {
                s="";
                for(int i=1;i<=l.size()+1;i++)
                    s+=to_string(i);
            }
        }
        cout<<s<<endl;
        while(stol(s)<=high)
        {
            
            if(stol(s)>=low)
                ans.push_back(stol(s));
            
            //cout<<"here"<<endl;
            int n=s.length();
            int c=s[n-1]-'0';
            
            if(c<9)
                s=s.substr(1)+to_string(c+1);
            else
            {
                string z="";
                for(int i=1;i<=n+1;i++)
                    z+=to_string(i);
                s=z;
            }
            
            
        }
        
        cout<<s<<endl;
        
        return ans;
    }
};