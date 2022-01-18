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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)
            return head;
        ListNode *temp = head;
        ListNode *a = new ListNode(0);
        ListNode *b = new ListNode(0);
        a->next = head;
        b->next = head;
        ListNode *a1 = a;
        ListNode *b1 = b;
        while(temp != NULL){
            if(temp->val < x){
                a1->next = temp;
                a1 = a1->next;
            }
            else{
                b1->next = temp;
                b1 = b1->next;
            }
            temp = temp->next;
        }
        b1->next = NULL;
        a1->next = b->next;
        return a->next;
    }
};