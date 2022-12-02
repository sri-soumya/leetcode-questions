class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<int, int> seen1, seen2;
        vector<int> freq1(26, 0), freq2(26, 0);
        if (word1.size() != word2.size()) return false;
        for (auto c : word1) ++freq1[c - 'a'];
        for (auto c : word2) ++freq2[c - 'a'];
        for (int i = 0; i < 26; ++i)
            if ((freq1[i] and !freq2[i]) or 
                (!freq1[i] and freq2[i])) return false;
        for (auto n : freq1) seen1[n]++;
        for (auto n : freq2) seen2[n]++;
        
        return seen1 == seen2;
    }
};