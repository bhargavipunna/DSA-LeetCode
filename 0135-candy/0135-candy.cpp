// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n = ratings.size();
//         int sum = n;

//         for(int i=0;i<n;i++){
//             if(i==0){
//                 if(i+1<n && ratings[i]>ratings[i+1]){
//                     sum+=1;
//                 }
//             }
        
//             else if(i==n-1){
//                 if(ratings[i]>ratings[i-1]){
//                 sum+=1;
//             }
//         }
//         else{

//         }
//         }
//     return sum;
//     }
// };
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

      
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

      
        int total = 0;
        for (int c : candies) {
            total += c;
        }

        return total;
    }
};