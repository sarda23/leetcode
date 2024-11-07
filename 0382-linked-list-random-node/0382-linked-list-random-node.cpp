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
    ListNode* Head;

    Solution(ListNode* head) {
        Head = head;
    }
    
    int getRandom() {
        int count = 1; // reservior sampling - ek ek kar ke element add ho rahe hai toh start 1
        int result = 0;

        ListNode* temp = Head;

        while(temp){
            if(rand() % count ==0){ // k/count
                result = temp->val;
            }
            count++;
            temp=temp->next;
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */