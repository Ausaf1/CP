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
    ListNode* reverseKGroup(ListNode* head, int k) {
          if (head == NULL)
            return NULL;
        
        int count = 0;
        ListNode *cNode = NULL, *nNode = NULL, *pNode = NULL;
        
        for (count = 0, cNode = head; count < k && cNode != NULL; cNode = cNode->next, ++count);
        
        if (count < k)
            return head;
        
        for (count = 0, cNode = head; count < k && cNode != NULL; ++count) {
            nNode = cNode->next;
            cNode->next = pNode;
            pNode = cNode;
            cNode = nNode;
        }
        
        head->next = reverseKGroup(cNode, k);
        
        return pNode;
    }
};