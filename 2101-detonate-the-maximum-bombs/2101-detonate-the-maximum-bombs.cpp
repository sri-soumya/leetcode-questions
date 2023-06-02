class Solution {
public:
    static const int MAXN = 103;
    vector <int> adj[MAXN];
    bool vis[MAXN];

    int cnt = 0;
    void DFS(int v){
        vis[v] = true;
        cnt++;
        for (int child : adj[v]){
            if (!vis[child]){
                DFS(child);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& a){
        int n = a.size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i != j && 1LL * (a[j][0] - a[i][0]) * (a[j][0] - a[i][0]) + 1LL * (a[j][1] - a[i][1]) * (a[j][1] - a[i][1]) <= 1LL * a[i][2] * a[i][2]){ // exploding bomb i will cause bomb j to detonate as well
                    adj[i].push_back(j);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++){
            if (!vis[i]){
                DFS(i);
                ans = max(ans, cnt);
                cnt = 0;
                for (int i = 0; i < n; i++){
                    vis[i] = false;
                }
            }
        }
        return ans;
    }
};
