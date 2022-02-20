class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        unordered_map<int,int> x;
        int c=0;
        for(int i=0;i<time.size();i++)
        {
            int a=time[i]%60;
            if(a&&x.count(60-a))
                c+=x[60-a];
            else if(!a&&x.count(0))
                c+=x[0];
            x[a]++;
        }
        return c;
    }
};