class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] == n-1){
            return true;
        }
        int i=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(i>cnt){
                return false;
            }
            cnt=max(cnt,i+nums[i]);
            if(cnt>=n-1){
            return true;
        }
        }
        
return false;
    }
};