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
    int length(ListNode* head){
        int l = 0;
        while(head){
            head = head->next;
            l++;
        }
        return l;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        int len = length(head);
        ListNode *startk = head;
        for(int i = 0;i < k-1;i++)
            startk = startk->next;
        ListNode *endk = head;
        for(int i = 0;i < len-k;i++)
            endk = endk->next;
        swap(startk->val,endk->val);
        return head;
    }
};