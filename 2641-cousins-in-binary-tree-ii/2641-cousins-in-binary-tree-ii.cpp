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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root){
            return root; // kuch hai hi nahi toh kya kroge
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<int> level_sum;

        while(!q.empty()){
            int curr_level_sum = 0;
            int n = q.size();

            while(n--){
                TreeNode* curr = q.front();
                q.pop();
                curr_level_sum += curr->val;
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            level_sum.push_back(curr_level_sum);
        }

        // step -2 
        q.push(root);
        root->val = 0;  // root has no cousin
        
        int idx = 1; // index 0 pe toh root hai - just niche wale se start karna hai

        while(!q.empty()){
            int n = q.size(); // current level me kitne nodes hai

            while(n--){ // saare nodes ko process karna hai
                TreeNode* curr = q.front();
                q.pop();

                // level_sum of curr_level - sibling_sum
                int sibling_sum = curr->left != NULL ? curr->left->val : 0;
                sibling_sum += curr->right!=NULL ? curr->right->val : 0;

                // curr_level_sum

                if(curr->left){
                    curr->left->val = level_sum[idx] - sibling_sum;
                    q.push(curr->left);
                }
                if(curr->right){
                    curr->right->val = level_sum[idx] - sibling_sum;
                    q.push(curr->right);
                }
            }
            idx++;
        }
        
        return root;
    }
};