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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *newHead = new ListNode(0,head);
        ListNode *temp1 = newHead;
        ListNode *temp2 = head;
        while(temp2 != NULL){
           bool isDuplicate = false;
           while(temp2->next && temp2->next->val == temp2->val){
               isDuplicate = true;
               temp2 = temp2->next;
           }
            if(isDuplicate)
                temp1->next = temp2->next;
            else
                temp1 = temp2;
            temp2 = temp2->next;
        }
        return newHead->next;
    }
};