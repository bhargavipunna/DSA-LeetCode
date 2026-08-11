class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        vector<int> ones;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                ones.push_back(i);
            }
        }

        if (ones.empty()) return 0;
        
        long long ans = 1;
        long long MOD = 1e9 + 7;

        for (size_t i = 0; i < ones.size() - 1; ++i) {
           
            long long gap = ones[i+1] - ones[i];
            ans = (ans * gap) % MOD;
        }

        return (int)ans;
    }
};