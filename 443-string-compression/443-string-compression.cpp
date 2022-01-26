class Solution {
public:
    int compress(vector<char>& chars) {
        
        int n=chars.size();
        
        int in=1,c=1;
        
        for(int i=1;i<n;i++)
        {
            if(chars[i]==chars[i-1])
                c++;
            else
            {
                if(c>1)
                {
                    string a=to_string(c);
                    int j=0;
                    while(j<a.length())
                        chars[in++]=a[j++];
                }
                
                chars[in++]=chars[i];
                c=1;
            }
        }
        
        if(c>1)
        {
            string a=to_string(c);
            int j=0;
            while(j<a.length())
                chars[in++]=a[j++];
        }
        
        return in;
        
    }
};