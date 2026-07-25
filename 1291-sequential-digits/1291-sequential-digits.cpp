class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> sequential;
        
        for (int i = 1; i <= 9; i++) {
            int num = 0;
           
            int current = i;
            while (current <= high) {
                if (current >= low && current <= high) {
                    sequential.push_back(current);
                }
                
                int lastDigit = current % 10;
                if (lastDigit >= 9) break;
                
                int nextDigit = lastDigit + 1;
                current = current * 10 + nextDigit;
            }
        }

        sort(sequential.begin(), sequential.end());
        
        return sequential;
    }
};