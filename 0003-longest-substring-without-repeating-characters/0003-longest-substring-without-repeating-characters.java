class Solution {
    public int lengthOfLongestSubstring(String s) {
        // HashSet<Character>ans = new HashSet<>();
        // int l = 0;
        // int max = 0;
        // for(int r=0;r<s.length();r++){
        //     if(ans.contains(s.charAt(r))){
        //         ans.remove(s.charAt(l));
        //         l++;
        //     }
        //     ans.add(s.charAt(r));
        //     max = Math.max(max,r-l+1);
        // }
        // return max;
        // HashMap<Character, Integer> map = new HashMap<>();

        // int left = 0;
        // int max = 0;

        // for (int right = 0; right < s.length(); right++) {
        //     char ch = s.charAt(right);

        //     if (map.containsKey(ch)) {
        //         left = Math.max(left, map.get(ch) + 1);
        //     }

        //     map.put(ch, right);
        //     max = Math.max(max, right - left + 1);
        // }

        // return max;
        int charIndex[] = new int[128];

        int maxLength=0, left=0;
        
        for(int right = 0; right<s.length(); right++){
            char ch = s.charAt(right);
            left = Math.max(left, charIndex[ch]);

            charIndex[ch] = right + 1;

            maxLength = Math.max(maxLength,right - left + 1); 
        }

        return maxLength;
    }
}