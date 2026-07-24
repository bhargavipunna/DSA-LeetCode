class Solution {
public:
int robLinear(const vector<int>& nums, int start, int end) {
        int next1 = 0; // Represents dp[i+1]
        int next2 = 0; // Represents dp[i+2]
        
        for (int i = end; i >= start; i--) {
            int current = max(nums[i] + next2, next1);
            next2 = next1;
            next1 = current;
        }
        return next1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int op1 = robLinear(nums,0,n-2);
        int op2 = robLinear(nums,1,n-1);

        
        return max(op1,op2);
    }
};