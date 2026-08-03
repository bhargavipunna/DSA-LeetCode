class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        priority_queue<int> maxHeap;
        int total = 0;  
        
        for (auto& course : courses) {
            int duration = course[0];
            int deadline = course[1];
            
            total += duration;
            maxHeap.push(duration);
            
            if (total > deadline) {
                total -= maxHeap.top();
                maxHeap.pop();
            }
        }
        
        return maxHeap.size();
    }
};