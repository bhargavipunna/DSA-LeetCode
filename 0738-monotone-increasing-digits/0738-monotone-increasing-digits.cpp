class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string digits = to_string(n);
        int length = digits.size();
        int marker = length;
        
        for (int i = length - 1; i > 0; i--) {
            if (digits[i-1] > digits[i]) { 
                digits[i-1]--;
                marker = i;
            }
        }
        
        for (int i = marker; i < length; i++) {
            digits[i] = '9';
        }
        
        return stoi(digits);
    }
};