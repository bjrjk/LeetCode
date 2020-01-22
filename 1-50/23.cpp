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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=new ListNode(-1);
        ListNode* ptr=head;
        ListNode* curListPtr;
        int pos;
        do{
            curListPtr=NULL;
            for(int i=0;i<lists.size();i++){
                if(!lists[i])continue;
                if(!curListPtr||lists[i]->val<curListPtr->val){
                    curListPtr=lists[i];
                    pos=i;
                }
            }
            if(curListPtr){
                ptr->next=new ListNode(curListPtr->val);
                ptr=ptr->next;
                lists[pos]=lists[pos]->next;
            }
        }while(curListPtr);
        return head->next;
    }
};
