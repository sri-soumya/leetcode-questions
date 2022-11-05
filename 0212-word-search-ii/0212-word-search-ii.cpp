class TrieNode {
public:
    unordered_map<char, TrieNode*> links;
    bool isLeaf;
    
    TrieNode() {
        isLeaf = false;
    }
};

class Solution {
    const vector<pair<int, int>> offsets = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
public:
    vector<string> res;
    string path;
    
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        TrieNode* node = root;
        
        for (string word: words) {
            for (char c: word) {
                if (!node->links.count(c))
                    node->links[c] = new TrieNode();
                node = node->links[c];
            }
            node->isLeaf = true;
            node = root;
        }
        
        return root;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                backtrack(board, root, i, j);
        return res;
    }
    
    void backtrack(vector<vector<char>>& board, TrieNode* node, int row, int col) {
        int m = board.size(), n = board[0].size();
        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] == '#' || !node->links.count(board[row][col]))
            return;
        
        char letter = board[row][col];
        path.push_back(letter);
        if (node->links[letter]->isLeaf) {
            res.push_back(path);
            node->links[letter]->isLeaf = false;
            
            if (node->links[letter]->links.empty()) {
                TrieNode* temp = node->links[letter];
                node->links.erase(letter);
                delete(temp);
                path.pop_back();
                return;
            }
        }
            
        board[row][col] = '#';
        for (auto offset: offsets)
            backtrack(board, node->links[letter], row + offset.first, col + offset.second);
        path.pop_back();
        board[row][col] = letter;
        
        if (node->links[letter]->links.empty()) {
            TrieNode* temp = node->links[letter];
            node->links.erase(letter);
            delete(temp);
        }
    }
};