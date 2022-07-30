class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<int> freq(26,0);
        
        for(auto x:words2)
        {
            for(char j='a';j<='z';j++)
            {
                int c=0;
                for(auto y:x)
                {
                    if(y==j)
                        c++;
                }
                
                freq[j-'a']=max(freq[j-'a'],c);
            }
        }
        
        vector<string> ans;
        
        for(auto x:words1)
        {
            bool f=true;
            for(char j='a';j<='z';j++)
            {
                int c=0;
                for(auto y:x)
                {
                    if(y==j)
                        c++;
                }
                
                if(c<freq[j-'a'])
                {
                    f=false;
                    break;
                }
            }
            
            if(f)
                ans.push_back(x);
        }
        
        return ans;
    }
};