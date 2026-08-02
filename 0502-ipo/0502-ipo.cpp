class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        // Pair up capital with profit, sort by capital ascending
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end());
        
        // Max-heap for profits of affordable projects
        priority_queue<int> maxHeap;
        
        int i = 0;  // pointer into sorted projects
        
        for (int j = 0; j < k; j++) {
            // Add all newly affordable projects to the heap
            while (i < n && projects[i].first <= w) {
                maxHeap.push(projects[i].second);
                i++;
            }
            
            // If no affordable project, stop early
            if (maxHeap.empty()) break;
            
            // Pick the project with maximum profit
            w += maxHeap.top();
            maxHeap.pop();
        }
        
        return w;
    }
};