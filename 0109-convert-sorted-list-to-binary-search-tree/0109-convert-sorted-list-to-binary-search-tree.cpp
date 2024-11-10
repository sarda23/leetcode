/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head){
            return NULL;
        }
        if(!head->next){
            return new TreeNode(head->val);
        }

        ListNode* slow = head; 
        ListNode* fast = head;
        ListNode* slow_prev = NULL; // 2 part me tohdna hai na toh previous ka need hai 

        while(fast && fast->next){ // fast ka next check ho raha hai toh 
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // ab slow pakka mid ko point kar raha hoga
        TreeNode* root = new TreeNode(slow->val);

        slow_prev->next = NULL; // 2 half me kardia 
        root->left = sortedListToBST(head);
        
        root->right = sortedListToBST(slow->next);

        return root;
    }
};