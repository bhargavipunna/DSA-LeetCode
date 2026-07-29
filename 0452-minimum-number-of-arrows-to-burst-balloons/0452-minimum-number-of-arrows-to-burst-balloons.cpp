class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1;
        int current_arrow_x = points[0][1];

        for (size_t i = 1; i < points.size(); i++) {
            
            if (points[i][0] > current_arrow_x) {
                arrows++;
                current_arrow_x = points[i][1]; 
            }
           
        }

        return arrows;
    }
};