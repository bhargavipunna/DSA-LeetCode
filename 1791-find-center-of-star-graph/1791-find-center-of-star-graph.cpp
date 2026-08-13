class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        if(n==1) return 1;
        vector<int>ans(n+1,0);
        for(auto &a:edges){
            ans[a[1]]++;
            ans[a[0]]++;
        }
        for(int i=1;i<=n;i++){
            if(ans[i] == n-1){
                return i;
            }
        }
        return -1;
    }
};