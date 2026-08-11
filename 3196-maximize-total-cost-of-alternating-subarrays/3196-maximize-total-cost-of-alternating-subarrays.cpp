class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        long long dp0 = nums[0];
        long long dp1 = LLONG_MIN;

        for (int i = 1; i < nums.size(); i++) {

            long long new0 = max(dp0, dp1) + nums[i];

            long long new1 = dp0 - nums[i];

            dp0 = new0;
            dp1 = new1;
        }

        return max(dp0, dp1);
    }
};