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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0)
            return head;
        int c = 1;
        ListNode *t = head; 
        while(t->next!=NULL){
            c++;
            t = t->next;
        }
        t->next = head;
        k = (c-k%c);
        while(k--)
            t = t->next;
        head = t->next;
        t->next = NULL;
        return head;
    }
};