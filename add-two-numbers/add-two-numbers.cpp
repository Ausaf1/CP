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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode *res  = new ListNode(0);
        ListNode *cpy=res;
       ListNode *p = l1, *q = l2;
        int carry = 0;
        while(p!=NULL or q!=NULL){
        int a = (p!=NULL) ? p->val : 0;
        int b = (q!=NULL) ? q->val : 0;
        int sum = carry + a + b;
        carry = sum/10;
            
        res->next = new ListNode(sum%10);
        res = res->next;
        
        if(p!=NULL)
            p = p->next; 
        if(q!=NULL)
         
            q = q->next; 
        }
        
        if(carry>0){
            res->next = new ListNode(carry);
        }
       return cpy->next;
    }
};