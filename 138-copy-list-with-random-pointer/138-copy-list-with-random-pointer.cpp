/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *newHead = NULL;
        Node *temp = head;
        Node *newTail = NULL;
        unordered_map<Node* , Node*> m;
        while(temp){
            if(newHead == NULL){
                newHead = new Node(temp->val);
                newTail = newHead;
            }
            else{
                newTail->next = new Node(temp->val);
                newTail = newTail->next;
            }
            m[temp] = newTail;
            temp = temp->next;
        }
        temp = newHead;
        while(temp){
            temp->random = m[head->random];
            head = head->next;
            temp = temp->next;
        }
        return newHead;
    }
};