class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return {};
        vector<int>temp(arr.begin(),arr.end());
        sort(temp.begin(),temp.end());
        vector<int>res;
        unordered_map<int, int> ranks;
        int rank = 1;
        for (int num : temp) {
            if (ranks.find(num) == ranks.end()) {
                ranks[num] = rank;
                rank++;
            }
        }
        for (int num : arr) {
            res.push_back(ranks[num]);
        }
        
        return res;

    }
};