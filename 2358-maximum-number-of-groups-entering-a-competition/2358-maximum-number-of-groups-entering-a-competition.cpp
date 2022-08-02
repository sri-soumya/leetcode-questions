class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        
        sort(grades.begin(),grades.end());
        
        int n=grades.size();
        int c=0,pc=0;
        int s=0,ps=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            s+=grades[i];
            c++;
            if(s>ps&&c>pc)
            {
                ans++;
                pc=c;
                ps=s;
                s=0;
                c=0;
            }
        }
        
        return ans;
    }
};