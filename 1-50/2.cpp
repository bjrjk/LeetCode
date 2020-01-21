/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * Remind: BigInt
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head=new ListNode(-1);
        ListNode * ptr=head;
        int carry=0,cur=0;
        while(l1||l2){
            cur=carry+(l1?l1->val:0)+(l2?l2->val:0);
            ptr->next=new ListNode(cur%10);
            carry=cur/10;
            ptr=ptr->next;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        if(carry)ptr->next=new ListNode(carry);
        return head->next;
    }
};
