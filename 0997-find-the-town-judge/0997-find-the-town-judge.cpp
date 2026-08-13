class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        vector<int>ans(n+1,0);
        for(auto &a:trust){
            ans[a[1]]++;
            ans[a[0]]--;
        }
        for(int i=1;i<=n;i++){
            if(ans[i] == n-1){
                return i;
            }
        }
        return -1;
    }
};