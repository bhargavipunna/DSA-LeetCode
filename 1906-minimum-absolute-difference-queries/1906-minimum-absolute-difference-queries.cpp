class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        
    int n = nums.size();

        vector<vector<int>> pre(n + 1, vector<int>(101));

        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i];
            pre[i + 1][nums[i]]++;
        }

        vector<int> ans;

        for (auto q : queries) {
            int l = q[0], r = q[1];
            int prev = -1, mn = INT_MAX;

            for (int x = 1; x <= 100; x++) {
                if (pre[r + 1][x] - pre[l][x] > 0) {
                    if (prev != -1)
                        mn = min(mn, x - prev);
                    prev = x;
                }
            }

            ans.push_back(mn == INT_MAX ? -1 : mn);
        }

        return ans;
    }
};