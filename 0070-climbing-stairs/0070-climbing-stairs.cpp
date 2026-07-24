// class Solution {
// public:
//     int climbStairs(int n) {
//         // if (n <= 2) return n;

//         // int prev2 = 1; 
//         // int prev1 = 2; 

//         // for (int i = 3; i <= n; i++) {
//         //     int curr = prev1 + prev2;
//         //     prev2 = prev1;
//         //     prev1 = curr;
//         // }
//         // return prev1;
        
//     }
// };
class Solution {
private:
    unordered_map<int, int> memo;
    
    int climb(int n) {
        // Base cases
        if (n <= 2) return n;
        
        // Check if already computed
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }
        
        // Compute and store in memo
        memo[n] = climb(n - 1) + climb(n - 2);
        return memo[n];
    }
    
public:
    int climbStairs(int n) {
        return climb(n);
    }
};