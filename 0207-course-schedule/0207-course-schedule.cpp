class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for (const auto& pair : prerequisites) {
            int course = pair[0];
            int prereq = pair[1];
            
            // Directed edge: prereq -> course
            adj[prereq].push_back(course);
            
            // Increment incoming dependency count for the course
            indegree[course]++;
        }

        // 2. Queue to hold all nodes ready to be processed (In-degree == 0)
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // 3. Process nodes level-by-level (Standard BFS Loop)
        int visitedCount = 0;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            // We have successfully "finished" this course
            visitedCount++;

            // Check all courses that depend on the current course
            for (int neighbor : adj[curr]) {
                indegree[neighbor]--; // Remove the dependency
                
                // If all prerequisites are cleared, add it to the queue
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // 4. If we successfully visited all courses, no cycle exists
        return visitedCount == numCourses;
    }
};