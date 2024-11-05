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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next){
            return NULL;
        }

        // to find middle we can follow slow and fast pointer
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev_to_slow = NULL;

        while(fast && fast->next){
            prev_to_slow = slow;
            
            slow = slow->next;

            fast = fast->next->next;
        }

        prev_to_slow->next = slow->next;
        delete(slow);

        return head;
    }
};