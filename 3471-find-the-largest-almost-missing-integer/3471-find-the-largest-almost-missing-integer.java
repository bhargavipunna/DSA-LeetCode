class Solution {
    public int largestInteger(int[] nums, int k) {
        HashMap<Integer,Integer> freq = new HashMap<>();
        int n = nums.length;
        for (int i = 0; i <= n - k; i++) {
            HashSet<Integer> set = new HashSet<>();
            for (int j = i; j < i + k; j++) {
                set.add(nums[j]);
            }
            for (int x : set) {
                freq.put(x, freq.getOrDefault(x, 0) + 1);
            }
        }
        int ans = -1;
        for(Map.Entry<Integer, Integer> entry : freq.entrySet()){
            if(entry.getValue()==1){
                ans = Math.max(ans,entry.getKey());
            }
        }
        return ans;

    }
}