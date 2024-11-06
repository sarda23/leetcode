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
    ListNode* oddEvenList(ListNode* head) {
        /*
        hume odd and even ko segregate karna hai
        toh let's take two pointer to point to ODD and EVEN nodes
        Unko alag alag segregate kardenge
        last me connect kardenge odd ko even se
        */
        if(!head || !head->next){
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;

        // last me connect karne ke lia odd ko even se
        ListNode* even_start = head->next;

        while(even != NULL && even->next != NULL){
            odd->next = even->next; // even ka next bhi null nahi hona chahiye
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        odd->next = even_start;

        return head;
    }
};