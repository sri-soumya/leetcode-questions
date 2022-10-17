class Solution {
public:
    bool checkIfPangram(string sentence) {
        map<int,int> mp;
        
        for(auto x:sentence){
            mp[x]++;
        }
        
        return mp.size()==26;
    }
};