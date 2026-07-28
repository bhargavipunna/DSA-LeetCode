/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
unordered_map<TreeNode*, int> mp;
int help(TreeNode* root,bool pr){
    if(root == nullptr){
        return 0;
    }
    if (mp.count(root)) {
            return mp[root];
        }
    int robCurrent = root->val;
        
        if (root->left != nullptr) {
            robCurrent += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right != nullptr) {
            robCurrent += rob(root->right->left) + rob(root->right->right);
        }

        
        int skipCurrent = rob(root->left) + rob(root->right);

        return mp[root] = max(robCurrent, skipCurrent);
}
    int rob(TreeNode* root) {
        return help(root,false);
    }
};