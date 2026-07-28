class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // int m = g.size();
        // int n = s.size();
        // if(n==0){
        //     return 0;
        // }
        // sort(g.begin(),g.end());
        // sort(s.begin(),s.end());
        // int i = 0;
        // int j = 0;
        // int cnt = 0;
        
        // while(i<m && j<n){
        //     if(g[i] <= s[j]){
        //         cnt++;
        //         j++;
        //         i++;
        //     }
        //     else{
        //         j++;
        //     }
        // }
        
        // return cnt;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int m = g.size();
        int n = s.size();
        int l = 0;
        int r = 0;
        while (l < m && r < n) {
            if (s[r] >= g[l]) {

                l = l + 1;
            }
            r = r + 1;
        }
        return l;
    }
};