class Solution {
public:
    bool check(int ind, string s, unordered_map<string, int>map, int len){
    int i = ind;
    while(i<s.length() and map.size()>0){            
        string temp = s.substr(i, len);
        if(map[temp]){
            map[temp]--;
            if(map[temp]==0)map.erase(temp);
            i+=len;
        }
        else{
            break;
        }
    }
    if(map.size()==0)return true;
    
    return false;
}
vector<int> findSubstring(string s, vector<string>& words) {
    unordered_map<string, int>map;
    for(auto ele : words){
        map[ele]++;
    }
    vector<int>ans;
    int len = words[0].size();
    int window = words.size()*len;
    int n = s.length()-(window)+1;
    for(int i = 0;i<n;i++){
        if(check(i, s, map, len)){
            ans.push_back(i);
        }
    }
    return ans;
}
};