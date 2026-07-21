class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size(); // Fixed: Get actual column size
        
        queue<pair<int, int>> q; 
        int freshCount = 0; 
        
        for (int i = 0; i < m; ++i) { 
            for (int j = 0; j < n; ++j) { 
                if (grid[i][j] == 2) { 
                    q.push({i, j}); 
                } else if (grid[i][j] == 1) { 
                    freshCount++; 
                } 
            } 
        } 
        
        if (freshCount == 0) return 0; 
        
        int minutes = 0; 
        // Fixed: Correct type, syntax, and formatting for directions
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
        
        while (!q.empty()) { 
            int size = q.size(); 
            bool spreadHappened = false; 
            
            for (int i = 0; i < size; ++i) { 
                auto [r, c] = q.front(); 
                q.pop(); 
                
                for (auto& d : dirs) { 
                    int nr = r + d.first;  // Fixed: Use direction offsets
                    int nc = c + d.second; // Fixed: Use direction offsets
                    
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) { 
                        grid[nr][nc] = 2; 
                        q.push({nr, nc}); 
                        freshCount--; 
                        spreadHappened = true; 
                    } 
                } 
            } 
            if (spreadHappened) { 
                minutes++; 
            } 
        } 
        
        // Fixed: Return an integer -1 instead of a string
        return freshCount == 0 ? minutes : -1; 
    }
};