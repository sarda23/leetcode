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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long,vector<long>,greater<long>> pq; // min heap

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            long level_sum = 0;
            while(n--){
                TreeNode* popped_node = q.front();
                q.pop();
                level_sum += popped_node->val;
                if(popped_node->left != NULL){
                    q.push(popped_node->left);
                }
                if(popped_node->right != NULL){
                    q.push(popped_node->right);
                }   
            }

            pq.push(level_sum);
            if(pq.size() > k){
                pq.pop();
            }
        }

        return pq.size() < k ? -1 : pq.top();
    }
};