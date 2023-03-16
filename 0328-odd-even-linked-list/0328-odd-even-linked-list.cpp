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
        if(head==NULL) return NULL;
        ListNode* odd=head;
        ListNode* even1=head->next;
        ListNode* even2=head->next;
        while(even1!=NULL && even1->next!=NULL){
            odd->next=odd->next->next;
            even1->next=even1->next->next;
            odd=odd->next;
            even1=even1->next;
        }
        odd->next=even2;
        return head;
    }
};