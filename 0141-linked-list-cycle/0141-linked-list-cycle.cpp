/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *temp, *tail;
        temp = head;
        tail = head;
        while(tail!=NULL && tail->next!=NULL){
            tail = tail->next->next;
            temp = temp->next;
            if(tail==temp){
                return true;
            }
        }
        return false;
    }
};