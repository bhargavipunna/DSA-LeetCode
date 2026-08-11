class Solution {
public:
    int findIntegers(int n) {
        int dp[32][2][2];
        memset(dp, -1, sizeof(dp));
        
        string s = "";
        while (n > 0) {
            s += (n % 2) ? '1' : '0';
            n /= 2;
        }
        reverse(s.begin(), s.end());
        
        return solve(0, 0, 1, s, dp);
    }
    
    int solve(int pos, int prev, int tight, const string& s, int dp[32][2][2]) {
        if (pos == s.size()) return 1;
        if (dp[pos][prev][tight] != -1) return dp[pos][prev][tight];
        
        int limit = tight ? (s[pos] - '0') : 1;
        int count = 0;
        
        for (int digit = 0; digit <= limit; ++digit) {
            if (prev == 1 && digit == 1) continue;
            count += solve(pos + 1, digit, tight && (digit == limit), s, dp);
        }
        
        return dp[pos][prev][tight] = count;
    }
};