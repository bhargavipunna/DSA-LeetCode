class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left=0,right=0;
        int n = nums.size();
        int ans = 1;
        unordered_map<int,int>freq;
        while(right<n){
            freq[nums[right]]++;
            if(freq[nums[right]]>k){
                while(nums[left]!=nums[right]){
                    freq[nums[left]]--;
                    left++;
                }
                freq[nums[left]]--;
                left++;
            }
            ans = max(ans,right-left+1);
            right++;
        }
    return ans;
    }
};