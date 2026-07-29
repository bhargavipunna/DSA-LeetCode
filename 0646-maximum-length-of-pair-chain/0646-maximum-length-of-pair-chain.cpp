class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.empty()) return 0;

        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int chainLength = 1;
        int current_end = pairs[0][1];

        for (size_t i = 1; i < pairs.size(); i++) {
            if (pairs[i][0] > current_end) {
                chainLength++;
                current_end = pairs[i][1]; 
            }
        }

        return chainLength;
    }
};