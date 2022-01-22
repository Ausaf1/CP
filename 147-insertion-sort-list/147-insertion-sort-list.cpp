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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *temp;
        while(true){
            temp = head;
            bool flag = false;
            while(temp!=NULL){
                if(temp->next!=NULL && temp->val > temp->next->val){
                    swap(temp->val,temp->next->val);
                    flag = true;
                }
                temp = temp->next;
            }
            if(flag == false)
                break;
        }
        return head;
    }
};