class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26, 0);
        for (int i = 0; i < s.length(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }
        
        vector<bool> inResult(26, false);
        string res = "";
        
        for (int i = 0; i < s.length(); i++) {
            char curr = s[i];
            
            if (inResult[curr - 'a']) continue;
            
            while (!res.empty() && res.back() > curr && i < lastIndex[res.back() - 'a']) {
                inResult[res.back() - 'a'] = false;
                res.pop_back();
            }
            
            res.push_back(curr);
            inResult[curr - 'a'] = true;
        }
        
        return res;
    }
};