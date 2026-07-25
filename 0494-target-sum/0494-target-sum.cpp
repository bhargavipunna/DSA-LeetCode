class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        if ((target + totalSum) % 2 != 0 || abs(target) > totalSum) {
            return 0;
        }
        
        int subsetTarget = (target + totalSum) / 2;
        
        vector<int> dp(subsetTarget + 1, 0);
        dp[0] = 1; 
        
        for (int num : nums) {
            for (int i = subsetTarget; i >= num; i--) {
                dp[i] += dp[i - num];
            }
        }
        
        return dp[subsetTarget];
    }
};