class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int l=0,r=0;

        for (int i = 0; i < n; i++) {
            int count1 = expandFromCenter(s, i, i);
            
            int count2 = expandFromCenter(s, i, i + 1);
            int len = max(count1,count2);
            if(len>r-l+1){
                l = i-(len-1)/2;
                r = i+len/2;
            }
        }
        
        return s.substr(l,r-l+1);
    }

    int expandFromCenter(const string& s, int left, int right) {
        
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;  
            right++; 
        }
        
        return right-left-1;
    
    }
};