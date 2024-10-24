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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // flip kar ke check kar lo -- without flip kar ke check kar lo agar same aata hai toh matlab flipequiv hai - and agar root ka value if diff hai toh matlab hi nahi hai aage/niche check karne ka
        // base case - dono root null hai - toh toh true hai
        // base case - agar ek null hai(num of nodes hi equal hi nahi hai)- false

        if(!root1 && !root2){
            return true;
        }

        if(!root1 || !root2){
            return false;
        }

        if(root1->val == root2->val){
            bool without_flip = flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right);

            bool with_flip = flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left);

            return without_flip || with_flip;
        }

        return false;
    }
};