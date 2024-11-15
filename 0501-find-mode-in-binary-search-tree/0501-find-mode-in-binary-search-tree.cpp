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

    unordered_map<int, int> mp;
    
    void dfs(TreeNode* root) {
        if(!root)
            return;
        
        dfs(root->left);
        mp[root->val]++;
        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        dfs(root);

        vector<int> ans;

        int max_f = 0;

        for(auto &it:mp){
            if(it.second > max_f){
                max_f = it.second;
                ans = {};
                ans.push_back(it.first);
            }
            else if(it.second == max_f){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};