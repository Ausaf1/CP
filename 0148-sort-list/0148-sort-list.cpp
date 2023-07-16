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
private:
    ListNode* merge(ListNode *left,ListNode *right){
        if(left == NULL) return right;
        if(right == NULL) return left;
        ListNode *ans = new ListNode(-1);
        ListNode *mptr = ans;
        while(left && right){
            if(left->val <= right->val){
                mptr->next = left;
                mptr = left;
                left = left->next;
            }
            else{
                mptr->next = right;
                mptr = right;
                right = right->next;
            }
        }
        if(left) mptr->next = left;
        if(right) mptr->next = right;
        return ans->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *temp = NULL,*slow = head,*fast = head;
        while(fast && fast->next){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);
        return merge(l1,l2);
    }
};