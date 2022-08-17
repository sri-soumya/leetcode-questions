class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
     
        map<string,int> mp;
        
        vector<string> a={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    for(auto x:words)
    {
        string ans="";
        for(auto y:x)
            ans+=a[y-'a'];
        mp[ans]++;
    }
    
    return mp.size();
}
};