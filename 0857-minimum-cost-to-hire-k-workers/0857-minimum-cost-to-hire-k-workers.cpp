class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        
        // Create (ratio, quality) pairs
        vector<pair<double, int>> workers;
        for (int i = 0; i < n; i++) {
            workers.push_back({(double)wage[i] / quality[i], quality[i]});
        }
        
        // Sort by ratio ascending
        sort(workers.begin(), workers.end());
        
        // Max-heap to keep k smallest qualities
        priority_queue<int> maxHeap;
        double sumQ = 0;
        double answer = 1e18;
        
        for (int i = 0; i < n; i++) {
            double ratio = workers[i].first;
            int q = workers[i].second;
            
            maxHeap.push(q);
            sumQ += q;
            
            // Keep only k smallest qualities
            if ((int)maxHeap.size() > k) {
                sumQ -= maxHeap.top();
                maxHeap.pop();
            }
            
            // When heap has k elements, current worker is the captain
            // (highest ratio in the group)
            if ((int)maxHeap.size() == k) {
                double cost = sumQ * ratio;
                answer = min(answer, cost);
            }
        }
        
        return answer;
    }
};