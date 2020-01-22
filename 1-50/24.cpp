/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* ptr1=head;
        ListNode* ptr2=head->next;
        ListNode* nxt=ptr2->next;
        ptr2->next=ptr1;
        ptr1->next=swapPairs(nxt);
        return ptr2;
    }
};
