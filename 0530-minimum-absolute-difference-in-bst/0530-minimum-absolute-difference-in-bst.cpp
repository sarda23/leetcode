/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int min_diff = INT_MAX;
    TreeNode* prev;
    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        inorder(root->left);

        if(prev != NULL){
            min_diff = min(min_diff, root->val-prev->val);
            cout<<min_diff<<endl;
        }

        prev = root; // right jane se pehele prev ko root kar do 

        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        prev = NULL;

        inorder(root);

        return min_diff;
    }
};