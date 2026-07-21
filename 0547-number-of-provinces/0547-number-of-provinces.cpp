class Solution {
public:
    void dfs(int u, int n, const vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[u] = true;
        for (int v = 0; v < n; ++v) {
            if (isConnected[u][v] == 1 && !visited[v]) {
                dfs(v, n, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int c = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                c++;
                dfs(i, n, isConnected, visited);
            }
        }
        return c;
    }
};