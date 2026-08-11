class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> dp(n + 1, 1e18);
        dp[0] = 0;

        for (int r = 1; r <= n; r++) {

            vector<int> freq(n, 0);
            int trimmed = 0;

            for (int l = r - 1; l >= 0; l--) {

                int x = nums[l];

                if (freq[x] == 1)
                    trimmed += 2;
                else if (freq[x] >= 2)
                    trimmed += 1;

                freq[x]++;

                dp[r] = min(dp[r],
                             dp[l] + k + trimmed);
            }
        }

        return dp[n];
    }
};